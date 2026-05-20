/* ===== 23c623f90 license.license_client:71 ===== */
/* ghidra_name=forced_23c623f90 entry=23c623f90 size=1265 */

longlong forced_23c623f90(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  
  plVar8 = DAT_23ee29cf0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (DAT_23ee29cf0 == (longlong *)0x0) {
LAB_23c623fce:
    DAT_23ee29cf0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29ce8,DAT_23ee29d18,0x10);
  }
  else {
    lVar11 = *DAT_23ee29cf0;
    if (1 < lVar11) {
      *DAT_23ee29cf0 = lVar11 + -1;
      goto LAB_23c623fce;
    }
    if (DAT_23ee29cf0[2] != 0) {
      *DAT_23ee29cf0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23c623fce;
    }
  }
  plVar4 = DAT_23ee29cf0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23ee29cf0 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  DAT_23ee29cf0[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar8;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar5 = DAT_23ee28388;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar5);
  if (plVar8 != (longlong *)0x0) {
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ee28418);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 != (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23ee28420);
      if (plVar8 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0x49;
        plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar8,DAT_23ee28428);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar10 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0x49;
          lVar11 = FUN_23e914090(param_1,plVar9,plVar10);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (lVar11 != 0) {
            lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar8 = *(longlong **)(lVar3 + 0x28);
            plVar4 = (longlong *)plVar8[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
            *(undefined4 *)(plVar8 + 8) = 0xffffffff;
            if (plVar4 != (longlong *)0x0) {
              plVar8[2] = 0;
              *plVar4 = *plVar4 + -1;
              if (*plVar4 == 0) {
                (**(code **)(plVar4[1] + 0x30))();
              }
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            plVar8[0xf] = 0;
            *plVar1 = *plVar1 + -1;
            if (*plVar1 == 0) {
              (**(code **)(plVar1[1] + 0x30))(plVar1);
            }
            *plVar2 = *plVar2 + -1;
            if (*plVar2 != 0) {
              return lVar11;
            }
            (**(code **)(plVar2[1] + 0x30))(plVar2);
            return lVar11;
          }
          goto LAB_23c6241c0;
        }
      }
      uVar5 = *(undefined8 *)(param_1 + 0x60);
      uVar6 = *(undefined8 *)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar9 = *plVar9 + -1;
      plVar10 = DAT_23ed6a4f8;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
        plVar10 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023c6241df;
    }
  }
LAB_23c6241c0:
  plVar8 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar5 = *(undefined8 *)(param_1 + 0x60);
  uVar6 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar10 = DAT_23ed6a4f8;
joined_r0x00023c6241df:
  DAT_23ed6a4f8 = plVar10;
  if (plVar8 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    plVar10[4] = 0x49ffffffff;
    lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar10[-1];
    puVar7 = *(undefined8 **)(lVar11 + 8);
    *puVar7 = plVar10 + -2;
    plVar10[-2] = lVar11;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar11 + 8) = plVar10 + -2;
    plVar9 = plVar10;
  }
  else {
    plVar9 = plVar8;
    if ((longlong *)plVar8[3] != plVar4) {
      if (plVar10 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar10;
        *plVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar10[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      plVar10[4] = 0x49ffffffff;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar10[-1];
      puVar7 = *(undefined8 **)(lVar11 + 8);
      *puVar7 = plVar10 + -2;
      plVar10[-2] = lVar11;
      plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar7;
      lVar3 = *plVar8;
      *(longlong **)(lVar11 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar8;
      plVar9 = plVar10;
      if (lVar3 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec47929,plVar1,plVar2);
  if (DAT_23ee29cf0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23ee29cf0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar11 + 0x28);
  plVar4 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar5,uVar6,plVar9);
  return 0;
}
