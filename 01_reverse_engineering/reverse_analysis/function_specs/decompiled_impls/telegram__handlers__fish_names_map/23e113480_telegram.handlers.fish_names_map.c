/* ===== 23e113480 telegram.handlers.fish_names_map:41 ===== */
/* ghidra_name=forced_23e113480 entry=23e113480 size=1617 */

longlong forced_23e113480(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  plVar7 = DAT_23eeab240;
  plVar2 = (longlong *)*param_3;
  if (DAT_23eeab240 == (longlong *)0x0) {
LAB_23e1134bd:
    DAT_23eeab240 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeab230,DAT_23eeab238,8);
  }
  else {
    lVar10 = *DAT_23eeab240;
    if (1 < lVar10) {
      *DAT_23eeab240 = lVar10 + -1;
      goto LAB_23e1134bd;
    }
    if (DAT_23eeab240[2] != 0) {
      *DAT_23eeab240 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e1134bd;
    }
  }
  plVar3 = DAT_23eeab240;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23eeab240 + 9;
  lVar12 = *(longlong *)(lVar10 + 8);
  DAT_23eeab240[0xf] = lVar12;
  *(longlong **)(lVar10 + 8) = plVar7;
  if ((lVar12 != 0) &&
     (((*(char *)(lVar12 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar12 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar12 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar12 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar12 = DAT_23eeab1b0;
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar10 = *(longlong *)(lVar12 + 0x20);
  if (*(char *)(lVar10 + 10) == '\0') {
    plVar7 = (longlong *)FUN_23a37a020(lVar12,DAT_23eeab1c0);
    if (plVar7 == (longlong *)0x0) goto LAB_23e113771;
    lVar12 = *plVar7;
LAB_23e113a88:
    if (lVar12 == 0) goto LAB_23e113771;
  }
  else {
    iVar6 = *(int *)(lVar10 + 0xc);
    if (*(int *)(lVar10 + 0xc) == 0) {
      *(int *)(lVar10 + 0xc) = DAT_23ec14c9c;
      iVar6 = DAT_23ec14c9c;
      DAT_23ec14c9c = DAT_23ec14c9c + 1;
    }
    if (DAT_23ec14c98 != iVar6) {
      DAT_23ec14c98 = iVar6;
      DAT_23eeab1a8 = FUN_23e8cbd60(lVar10,DAT_23eeab1c0,*(undefined8 *)(DAT_23eeab1c0 + 0x18));
    }
    if (-1 < DAT_23eeab1a8) {
      lVar1 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
      lVar12 = *(longlong *)(lVar1 + 8 + DAT_23eeab1a8 * 0x10);
      if (lVar12 != 0) goto LAB_23e1135ad;
      DAT_23eeab1a8 = FUN_23e8cbd60(lVar10,DAT_23eeab1c0,*(undefined8 *)(DAT_23eeab1c0 + 0x18));
      if (-1 < DAT_23eeab1a8) {
        lVar12 = *(longlong *)(lVar1 + 8 + DAT_23eeab1a8 * 0x10);
        goto LAB_23e113a88;
      }
    }
LAB_23e113771:
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeab1c0);
    if ((plVar7 == (longlong *)0x0) || (lVar12 = *plVar7, lVar12 == 0)) {
      FUN_23e915740(param_1,&plStack_68,DAT_23eeab1c0);
      plVar9 = plStack_68;
      plVar8 = plStack_60;
      plVar5 = plStack_58;
      plVar11 = DAT_23ed6a4f8;
      goto joined_r0x00023e113963;
    }
  }
LAB_23e1135ad:
  plVar7 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23ed6ce40);
  if (plVar7 == (longlong *)0x0) {
LAB_23e113a00:
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar5 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = *(longlong **)(param_1 + 0x68);
    plVar11 = DAT_23ed6a4f8;
  }
  else {
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeab1c8);
    if (plVar8 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0x2b;
      plVar9 = (longlong *)FUN_23e9557e0(param_1,plVar8,DAT_23eeab1d0);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar9 != (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eeab1d8);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar8 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0x2b;
          plVar9 = (longlong *)FUN_23e91a870(param_1,plVar8);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar9 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0x2b;
            plStack_68 = plVar2;
            plStack_60 = plVar9;
            lVar10 = FUN_23e94ed00(param_1,plVar7,&plStack_68);
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (lVar10 != 0) {
              lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar7 = *(longlong **)(lVar12 + 0x28);
              plVar3 = (longlong *)plVar7[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
              *(undefined4 *)(plVar7 + 8) = 0xffffffff;
              if (plVar3 != (longlong *)0x0) {
                plVar7[2] = 0;
                *plVar3 = *plVar3 + -1;
                if (*plVar3 == 0) {
                  (**(code **)(plVar3[1] + 0x30))();
                }
              }
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              plVar7[0xf] = 0;
              *plVar2 = *plVar2 + -1;
              if (*plVar2 != 0) {
                return lVar10;
              }
              (**(code **)(plVar2[1] + 0x30))(plVar2);
              return lVar10;
            }
            goto LAB_23e113a00;
          }
        }
      }
    }
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x68);
    plVar5 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar7 = *plVar7 + -1;
    plVar11 = DAT_23ed6a4f8;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
      plVar11 = DAT_23ed6a4f8;
    }
  }
joined_r0x00023e113963:
  DAT_23ed6a4f8 = plVar11;
  if (plVar5 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar11[3] = (longlong)plVar3;
    plVar11[2] = 0;
    *plVar3 = *plVar3 + 1;
    plVar11[4] = 0x2bffffffff;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar12 = plVar11[-1];
    puVar4 = *(undefined8 **)(lVar10 + 8);
    *puVar4 = plVar11 + -2;
    plVar11[-2] = lVar10;
    plVar11[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar10 + 8) = plVar11 + -2;
    plVar7 = plVar11;
  }
  else {
    plVar7 = plVar5;
    if ((longlong *)plVar5[3] != plVar3) {
      if (plVar11 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar11;
        *plVar11 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar11[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      plVar11[4] = 0x2bffffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar12 = plVar11[-1];
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = plVar11 + -2;
      plVar11[-2] = lVar10;
      plVar11[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
      lVar12 = *plVar5;
      *(longlong **)(lVar10 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar5;
      plVar7 = plVar11;
      if (lVar12 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5a08d,plVar2);
  if (DAT_23eeab240 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eeab240 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  plVar5 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar9,plVar8,plVar7);
  return 0;
}
