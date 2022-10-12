import { press, takeScreenshot } from "react-native-owl";

const mapKeys = <T extends object>(obj: T) => Object.keys(obj) as (keyof T)[];

const tests = {
  Tests: ["HelloWorld"],
  API: ["Shapes", "Images", "PathEffect", "Transform"],
};

mapKeys(tests).forEach((id) => {
  const examples = tests[id];
  describe(`${id}`, () => {
    beforeAll(async () => {
      await press(id);
    });

    examples.forEach((example: string) => {
      it(`should render ${example}`, async () => {
        await press(example);
        const screen = await takeScreenshot(`${id}_${example}`);
        expect(screen).toMatchBaseline();
      });
    });

    afterAll(async () => {
      await press("back");
    });
  });
});
