/* ===== 23aaba460 __parents_main__:165 ===== */
/* ghidra_name=FUN_23aaba460 entry=23aaba460 size=3492 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23aaba460(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  code *pcVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined8 *puVar17;
  longlong *plVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  longlong **pplStack_230;
  undefined8 uStack_228;
  longlong *plStack_218;
  undefined8 uStack_210;
  longlong *plStack_208;
  longlong *plStack_1f8;
  undefined8 uStack_1f0;
  longlong *plStack_1e0;
  longlong *plStack_1d8;
  longlong lStack_1d0;
  longlong *plStack_1c8;
  longlong *plStack_1c0;
  longlong *plStack_1b8;
  longlong *plStack_1b0;
  undefined8 *puStack_1a8;
  longlong *plStack_180;
  longlong *plStack_178;
  longlong *plStack_170;
  longlong **pplStack_158;
  longlong *plStack_150;
  undefined8 uStack_148;
  longlong *plStack_140;
  undefined8 uStack_138;
  longlong *plStack_130;
  longlong *plStack_120;
  undefined8 uStack_118;
  longlong *plStack_108;
  longlong lStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  undefined8 *puStack_d8;
  undefined8 *puStack_d0;
  longlong *local_a8;
  code *local_90;
  longlong *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar6 = DAT_23ed90ab8;
  plVar13 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (DAT_23ed90ab8 == (longlong *)0x0) {
LAB_23aaba4b4:
    puStack_d0 = (undefined8 *)0x23aaba4d0;
    DAT_23ed90ab8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ed90ab0,DAT_23ed90b40,0x18);
  }
  else {
    lVar10 = *DAT_23ed90ab8;
    if (1 < lVar10) {
      *DAT_23ed90ab8 = lVar10 + -1;
      goto LAB_23aaba4b4;
    }
    if (DAT_23ed90ab8[2] != 0) {
      *DAT_23ed90ab8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        puStack_d0 = (undefined8 *)0x23aabaa22;
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23aaba4b4;
    }
  }
  plVar2 = DAT_23ed90ab8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar6 = DAT_23ed90ab8 + 9;
  lVar15 = *(longlong *)(lVar10 + 8);
  DAT_23ed90ab8[0xf] = lVar15;
  *(longlong **)(lVar10 + 8) = plVar6;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar22 = DAT_23ed8f528;
  *(undefined4 *)(plVar2 + 8) = 0;
  puStack_d0 = (undefined8 *)0x23aaba546;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar13,uVar22);
  if (plVar6 == (longlong *)0x0) {
LAB_23aaba800:
    plVar7 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar22 = *(undefined8 *)(param_1 + 0x60);
    uVar21 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    *(undefined4 *)(plVar2 + 5) = 0xae;
    puStack_d0 = (undefined8 *)0x23aaba56b;
    plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar6,DAT_23ed8f560);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      puStack_d0 = (undefined8 *)0x23aaba7ea;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
      if (plVar7 != (longlong *)0x0) goto LAB_23aaba581;
      goto LAB_23aaba800;
    }
    if (plVar7 == (longlong *)0x0) goto LAB_23aaba800;
LAB_23aaba581:
    puStack_d0 = (undefined8 *)0x23aaba589;
    plVar6 = (longlong *)FUN_23a388310(plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      puStack_d0 = (undefined8 *)0x23aaba9fa;
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar6 == (longlong *)0x0) goto LAB_23aaba800;
    puStack_d0 = (undefined8 *)0x23aaba5b3;
    plVar8 = (longlong *)(**(code **)(plVar6[1] + 0xe0))(plVar6);
    if (plVar8 == (longlong *)0x0) {
      puStack_d0 = (undefined8 *)0x23aabaa64;
      plVar8 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,2);
      if (plVar8 != (longlong *)0x0) goto LAB_23aaba5bf;
      plVar9 = (longlong *)0x0;
    }
    else {
LAB_23aaba5bf:
      puStack_d0 = (undefined8 *)0x23aaba5cd;
      plVar9 = (longlong *)(**(code **)(plVar6[1] + 0xe0))(plVar6);
      if (plVar9 == (longlong *)0x0) {
        puStack_d0 = (undefined8 *)0x23aabadb7;
        plVar9 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,2);
        if (plVar9 == (longlong *)0x0) goto LAB_23aabaa80;
      }
      puStack_d0 = (undefined8 *)0x23aaba5ed;
      cVar4 = FUN_23a3884a0(param_1,local_78,plVar6,2);
      if (cVar4 != '\0') {
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          puStack_d0 = (undefined8 *)0x23aaba607;
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        if (*plVar8 == 0) {
          puStack_d0 = (undefined8 *)0x23aaba617;
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (*plVar9 == 0) {
          puStack_d0 = (undefined8 *)0x23aabab1a;
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        puStack_d0 = (undefined8 *)0x23aaba62a;
        iVar5 = FUN_23a35f020(plVar8);
        if (iVar5 == -1) {
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          uVar20 = 0xb0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23aaba82d;
        }
        if (iVar5 == 0) {
          puStack_d0 = (undefined8 *)0x23aabab35;
          lVar10 = FUN_23ebc07d0();
          if (lVar10 == 0) {
            uVar20 = 0xb4;
            puStack_d0 = (undefined8 *)0x23aabb188;
            FUN_23e915740(param_1,local_78,DAT_23ed8f388);
            goto LAB_23aaba82d;
          }
          puStack_d0 = (undefined8 *)0x23aabab4d;
          plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8f450);
          plVar6 = DAT_23ed8f570;
          if (plVar7 == (longlong *)0x0) {
LAB_23aabb0b8:
            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            uVar20 = 0xb4;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23aaba82d;
          }
          lVar10 = *(longlong *)(param_1 + 0x10);
          plVar14 = *(longlong **)(lVar10 + 0xe20);
          local_90 = (code *)plVar7;
          if (plVar14 == (longlong *)0x0) {
            puStack_d0 = (undefined8 *)0x23aabaf46;
            plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar15 = plVar14[3];
            *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
            *(longlong *)(lVar10 + 0xe20) = lVar15;
            *plVar14 = 1;
          }
          pcVar11 = _PyRuntime_exref;
          plVar14[4] = 0;
          lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
          lVar15 = plVar14[-1];
          puVar17 = *(undefined8 **)(lVar10 + 8);
          *puVar17 = plVar14 + -2;
          plVar14[-2] = lVar10;
          plVar14[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar17;
          *(longlong **)(lVar10 + 8) = plVar14 + -2;
          *plVar6 = *plVar6 + 1;
          plVar14[3] = (longlong)plVar6;
          uVar22 = DAT_23ed6cd28;
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            puStack_d0 = (undefined8 *)0x23aabb14c;
            plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar6 == (longlong *)0x0) goto LAB_23aabb283;
            *plVar6 = *plVar6 + 1;
            DAT_23ed6a4c0 = plVar6;
          }
          uStack_80 = uVar22;
          puStack_d0 = (undefined8 *)0x23aabac24;
          local_88 = plVar9;
          lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
          if (lVar10 == 0) {
            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(longlong *)local_90 = *(longlong *)local_90 + -1;
            if (*(longlong *)local_90 == 0) {
              puStack_d0 = (undefined8 *)0x23aabb093;
              (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              puStack_d0 = (undefined8 *)0x23aabb0a5;
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            uVar20 = 0xb4;
            goto LAB_23aaba82d;
          }
          plVar14[4] = lVar10;
          puStack_d0 = (undefined8 *)0x23aabac49;
          plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            puStack_d0 = (undefined8 *)0x23aabaed3;
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar6 != (longlong *)0x0) {
            *(undefined4 *)(plVar2 + 5) = 0xb4;
            puStack_d0 = (undefined8 *)0x23aabac7f;
            plVar7 = (longlong *)FUN_23e914090(param_1,local_90,plVar6);
            *(longlong *)local_90 = *(longlong *)local_90 + -1;
            if (*(longlong *)local_90 == 0) {
              puStack_d0 = (undefined8 *)0x23aabac97;
              (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
            }
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              puStack_d0 = (undefined8 *)0x23aabaf1a;
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            if (plVar7 != (longlong *)0x0) {
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                puStack_d0 = (undefined8 *)0x23aabaf2b;
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              *(undefined4 *)(plVar2 + 5) = 0xb7;
              puStack_d0 = (undefined8 *)0x23aabacce;
              pcVar11 = (code *)FUN_23e91bfe0(param_1,plVar13,DAT_23ed8f578);
              if (pcVar11 == (code *)0x0) {
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar20 = 0xb7;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23aaba82d;
              }
              goto LAB_23aabacd7;
            }
            goto LAB_23aabb0b8;
          }
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0xb4;
          uVar20 = 0xb4;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(longlong *)local_90 = *(longlong *)local_90 + -1;
          lVar10 = *(longlong *)local_90;
joined_r0x00023aabb1fd:
          if (lVar10 == 0) {
            puStack_d0 = (undefined8 *)0x23aabb20d;
            (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
            uVar20 = uVar19;
          }
        }
        else {
          puStack_d0 = (undefined8 *)0x23aaba640;
          lVar10 = FUN_23ebc07d0();
          if (lVar10 == 0) {
            uVar20 = 0xb1;
            puStack_d0 = (undefined8 *)0x23aabb1b0;
            FUN_23e915740(param_1,local_78,DAT_23ed8f388);
            goto LAB_23aaba82d;
          }
          puStack_d0 = (undefined8 *)0x23aaba658;
          plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8f390);
          plVar6 = DAT_23ed8f568;
          if (plVar7 != (longlong *)0x0) {
            lVar10 = *(longlong *)(param_1 + 0x10);
            plVar14 = *(longlong **)(lVar10 + 0xe20);
            local_90 = (code *)plVar7;
            if (plVar14 == (longlong *)0x0) {
              puStack_d0 = (undefined8 *)0x23aabaf6e;
              plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar15 = plVar14[3];
              *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
              *(longlong *)(lVar10 + 0xe20) = lVar15;
              *plVar14 = 1;
            }
            pcVar11 = _PyRuntime_exref;
            plVar14[4] = 0;
            lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
            lVar15 = plVar14[-1];
            puVar17 = *(undefined8 **)(lVar10 + 8);
            *puVar17 = plVar14 + -2;
            plVar14[-2] = lVar10;
            plVar14[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar17;
            *(longlong **)(lVar10 + 8) = plVar14 + -2;
            *plVar6 = *plVar6 + 1;
            plVar14[3] = (longlong)plVar6;
            uVar22 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              puStack_d0 = (undefined8 *)0x23aabb10c;
              plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar6 == (longlong *)0x0) {
LAB_23aabb283:
                puStack_d0 = (undefined8 *)0x23aabb28b;
                PyErr_PrintEx(0,0);
                lVar10 = 1;
                puStack_d0 = (undefined8 *)0x23aabb296;
                Py_Exit();
                plVar16 = DAT_23ed90aa8;
                puStack_d0 = &DAT_23ed6cce0;
                puStack_d8 = &DAT_23ed6a4c0;
                plVar6 = (longlong *)*puVar17;
                plVar7 = (longlong *)puVar17[1];
                plStack_120 = plVar9;
                uStack_118 = uVar22;
                plStack_108 = plVar2;
                lStack_100 = param_1;
                plStack_f8 = plVar8;
                plStack_f0 = plVar9;
                plStack_e8 = plVar14;
                plStack_e0 = plVar13;
                if (DAT_23ed90aa8 == (longlong *)0x0) {
LAB_23aabb2e9:
                  puStack_1a8 = (undefined8 *)0x23aabb305;
                  DAT_23ed90aa8 = (longlong *)FUN_23e91f3b0(lVar10,DAT_23ed90aa0,DAT_23ed90b40,0x28)
                  ;
                }
                else {
                  lVar15 = *DAT_23ed90aa8;
                  if (1 < lVar15) {
                    *DAT_23ed90aa8 = lVar15 + -1;
                    goto LAB_23aabb2e9;
                  }
                  if (DAT_23ed90aa8[2] != 0) {
                    *DAT_23ed90aa8 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      puStack_1a8 = (undefined8 *)0x23aabb672;
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    goto LAB_23aabb2e9;
                  }
                }
                plVar2 = DAT_23ed90aa8;
                lVar15 = *(longlong *)(lVar10 + 0x38);
                plVar13 = DAT_23ed90aa8 + 9;
                lVar12 = *(longlong *)(lVar15 + 8);
                DAT_23ed90aa8[0xf] = lVar12;
                *(longlong **)(lVar15 + 8) = plVar13;
                if (((lVar12 != 0) &&
                    ((*(char *)(lVar12 + 0x45) == '\x01' ||
                     ((ulonglong)
                      (*(longlong *)(lVar12 + 0x20) + 0xb8 +
                      (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
                      *(ulonglong *)(lVar12 + 0x38))))) && (plVar2[0xe] != 0)) {
                  plVar13 = *(longlong **)(lVar12 + 0x28);
                  *(longlong **)(plVar2[0xe] + 0x10) = plVar13;
                  if (plVar13 != (longlong *)0x0) {
                    *plVar13 = *plVar13 + 1;
                  }
                }
                *plVar2 = *plVar2 + 1;
                *(undefined4 *)(plVar2 + 8) = 0;
                puStack_1a8 = (undefined8 *)0x23aabb371;
                lVar12 = FUN_23ebc07d0();
                lVar15 = DAT_23ed8f588;
                if (lVar12 == 0) {
                  plVar9 = (longlong *)0x0;
                  plVar14 = (longlong *)0x0;
                  puStack_1a8 = (undefined8 *)0x23aabbe29;
                  FUN_23e915740(lVar10,&plStack_140,DAT_23ed8f388);
                  uVar20 = 0xc3;
                  plVar8 = (longlong *)0x0;
                  plVar13 = plStack_130;
                  plVar16 = DAT_23ed6a4f8;
                  pplStack_158 = (longlong **)uStack_138;
                  plStack_150 = plStack_140;
                  plVar3 = uStack_148;
                  goto joined_r0x00023aabbaf3;
                }
                *(undefined4 *)(plVar2 + 5) = 0xc3;
                puStack_1a8 = (undefined8 *)0x23aabb3a1;
                plVar13 = (longlong *)
                          FUN_23e915840(lVar10,lVar12,DAT_23ed8f390,*(undefined8 *)(lVar15 + 0x18));
                if (plVar13 == (longlong *)0x0) {
                  plStack_150 = *(longlong **)(lVar10 + 0x60);
                  plVar13 = *(longlong **)(lVar10 + 0x70);
                  plVar9 = (longlong *)0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  plVar14 = (longlong *)0x0;
                  uVar20 = 0xc3;
                  pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  plVar8 = (longlong *)0x0;
                  plVar16 = DAT_23ed6a4f8;
                  plVar3 = uStack_148;
                  goto joined_r0x00023aabbaf3;
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  puStack_1a8 = (undefined8 *)0x23aabb64a;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                puStack_1a8 = (undefined8 *)0x23aabb3bf;
                iVar5 = FUN_23a35f020(plVar7);
                if (iVar5 == -1) {
                  plStack_150 = *(longlong **)(lVar10 + 0x60);
                  plVar13 = *(longlong **)(lVar10 + 0x70);
                  plVar9 = (longlong *)0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  uVar20 = 0xc6;
                  plVar14 = (longlong *)0x0;
                  plVar8 = (longlong *)0x0;
                  pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  plVar16 = DAT_23ed6a4f8;
                  plVar3 = uStack_148;
                  goto joined_r0x00023aabbaf3;
                }
                plVar8 = (longlong *)0x0;
                if (iVar5 != 0) {
                  puStack_1a8 = (undefined8 *)0x23aabb685;
                  lVar15 = FUN_23ebc0680();
                  if (lVar15 == 0) {
                    plVar9 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                    puStack_1a8 = (undefined8 *)0x23aabc181;
                    FUN_23e915740(lVar10,&plStack_140,DAT_23ed8f590);
                    uVar20 = 199;
                    plVar8 = (longlong *)0x0;
                    plVar13 = plStack_130;
                    plVar16 = DAT_23ed6a4f8;
                    pplStack_158 = (longlong **)uStack_138;
                    plStack_150 = plStack_140;
                    plVar3 = uStack_148;
                    goto joined_r0x00023aabbaf3;
                  }
                  *(undefined4 *)(plVar2 + 5) = 199;
                  puStack_1a8 = (undefined8 *)0x23aabb6a3;
                  plVar8 = (longlong *)FUN_23e91a870(lVar10,lVar15);
                  if (plVar8 == (longlong *)0x0) {
                    plStack_150 = *(longlong **)(lVar10 + 0x60);
                    plVar13 = *(longlong **)(lVar10 + 0x70);
                    plVar9 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    plVar14 = (longlong *)0x0;
                    uVar20 = 199;
                    pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                    goto joined_r0x00023aabbaf3;
                  }
                  puStack_1a8 = (undefined8 *)0x23aabb6be;
                  plVar16 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8f598);
                  if (plVar16 == (longlong *)0x0) {
                    plStack_150 = *(longlong **)(lVar10 + 0x60);
                    plVar13 = *(longlong **)(lVar10 + 0x70);
                    plVar14 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uVar20 = 200;
                    pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar9 = (longlong *)0x0;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                    goto joined_r0x00023aabbaf3;
                  }
                  puStack_1a8 = (undefined8 *)0x23aabb6cf;
                  lVar15 = FUN_23ebc0680();
                  if (lVar15 == 0) {
                    puStack_1a8 = (undefined8 *)0x23aabc204;
                    FUN_23e915740(lVar10,&plStack_140,DAT_23ed8f590);
                    *plVar16 = *plVar16 + -1;
                    lVar15 = *plVar16;
                    plStack_150 = plStack_140;
                    pplStack_158 = (longlong **)uStack_138;
                    plVar13 = plStack_130;
                  }
                  else {
                    puStack_1a8 = (undefined8 *)0x23aabb6ea;
                    plVar13 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23ed8f5a0);
                    if (plVar13 != (longlong *)0x0) {
                      puStack_1a8 = (undefined8 *)0x23aabb705;
                      plVar9 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8f5a8);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aabb718;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if (plVar9 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          plVar14 = (longlong *)0x0;
                          plVar9 = (longlong *)0x0;
                          puStack_1a8 = (undefined8 *)0x23aabc270;
                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                          uVar20 = 200;
                          plVar16 = DAT_23ed6a4f8;
                          plVar3 = uStack_148;
                        }
                        else {
                          plVar9 = (longlong *)0x0;
                          plVar14 = (longlong *)0x0;
                          uVar20 = 200;
                          plVar16 = DAT_23ed6a4f8;
                          plVar3 = uStack_148;
                        }
                        goto joined_r0x00023aabbaf3;
                      }
                      *(undefined4 *)(plVar2 + 5) = 200;
                      puStack_1a8 = (undefined8 *)0x23aabb736;
                      plVar13 = (longlong *)FUN_23e914090(lVar10,plVar16,plVar9);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aabb74a;
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aabb75c;
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      if (plVar13 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        plVar9 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar20 = 200;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = (longlong *)0x0;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                        goto joined_r0x00023aabbaf3;
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aabc01a;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      lVar15 = DAT_23ed8f5b8;
                      *(undefined4 *)(plVar2 + 5) = 0xc9;
                      puStack_1a8 = (undefined8 *)0x23aabb793;
                      plVar13 = (longlong *)
                                FUN_23e915840(lVar10,plVar8,DAT_23ed8f5b0,
                                              *(undefined8 *)(lVar15 + 0x18));
                      if (plVar13 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        plVar9 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar20 = 0xc9;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = (longlong *)0x0;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                        goto joined_r0x00023aabbaf3;
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aabc03a;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      lVar15 = DAT_23ed8f5c8;
                      *(undefined4 *)(plVar2 + 5) = 0xca;
                      puStack_1a8 = (undefined8 *)0x23aabb7cd;
                      puVar17 = DAT_23ed8f5c0;
                      plVar13 = (longlong *)
                                FUN_23e915840(lVar10,plVar8,DAT_23ed8f5c0,
                                              *(undefined8 *)(lVar15 + 0x18));
                      if (plVar13 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        plVar9 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar20 = 0xca;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = (longlong *)0x0;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                        goto joined_r0x00023aabbaf3;
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aabc04a;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      puStack_1a8 = (undefined8 *)0x23aabb7f2;
                      plVar16 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8f5d0);
                      uVar22 = DAT_23ed6cd28;
                      if (plVar16 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        plVar14 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar20 = 0xcb;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar9 = (longlong *)0x0;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                        goto joined_r0x00023aabbaf3;
                      }
                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                        puStack_1a8 = (undefined8 *)0x23aabc387;
                        plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                        if (plVar13 == (longlong *)0x0) {
                          puStack_1a8 = (undefined8 *)0x23aabc633;
                          PyErr_PrintEx(0,0);
                          lVar15 = 1;
                          puStack_1a8 = (undefined8 *)0x23aabc63e;
                          Py_Exit();
                          plVar3 = _DAT_23ed90a90;
                          puStack_1a8 = &DAT_23ed6a4c0;
                          uStack_1f0 = uVar22;
                          plVar13 = (longlong *)*puVar17;
                          plVar14 = (longlong *)puVar17[1];
                          plStack_1f8 = plVar7;
                          plStack_1e0 = plVar2;
                          plStack_1d8 = plVar8;
                          lStack_1d0 = lVar10;
                          plStack_1c8 = plVar16;
                          plStack_1c0 = plVar9;
                          plStack_1b8 = plVar7;
                          plStack_1b0 = plVar6;
                          if (_DAT_23ed90a90 == (longlong *)0x0) {
LAB_23aabc686:
                            _DAT_23ed90a90 =
                                 (longlong *)FUN_23e91f3b0(lVar15,DAT_23ed90a88,DAT_23ed90b40,0x20);
                          }
                          else {
                            lVar10 = *_DAT_23ed90a90;
                            if (1 < lVar10) {
                              *_DAT_23ed90a90 = lVar10 + -1;
                              goto LAB_23aabc686;
                            }
                            if (_DAT_23ed90a90[2] != 0) {
                              *_DAT_23ed90a90 = lVar10 + -1;
                              if (lVar10 + -1 == 0) {
                                (**(code **)(plVar3[1] + 0x30))(plVar3);
                              }
                              goto LAB_23aabc686;
                            }
                          }
                          plVar2 = _DAT_23ed90a90;
                          lVar10 = *(longlong *)(lVar15 + 0x38);
                          plVar6 = _DAT_23ed90a90 + 9;
                          lVar12 = *(longlong *)(lVar10 + 8);
                          _DAT_23ed90a90[0xf] = lVar12;
                          *(longlong **)(lVar10 + 8) = plVar6;
                          if (((lVar12 != 0) &&
                              ((*(char *)(lVar12 + 0x45) == '\x01' ||
                               ((ulonglong)
                                (*(longlong *)(lVar12 + 0x20) + 0xb8 +
                                (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
                                *(ulonglong *)(lVar12 + 0x38))))) && (plVar2[0xe] != 0)) {
                            plVar6 = *(longlong **)(lVar12 + 0x28);
                            *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
                            if (plVar6 != (longlong *)0x0) {
                              *plVar6 = *plVar6 + 1;
                            }
                          }
                          *plVar2 = *plVar2 + 1;
                          *(undefined4 *)(plVar2 + 8) = 0;
                          lVar10 = FUN_23ebc07d0();
                          if (lVar10 == 0) {
                            plVar8 = (longlong *)0x0;
                            FUN_23e915740(lVar15,&plStack_218,DAT_23ed8f388);
                            uVar20 = 0xe6;
                            pplStack_230 = (longlong **)plStack_218;
                            uStack_228 = uStack_210;
                            plVar7 = (longlong *)0x0;
                            plVar6 = plStack_208;
                            goto LAB_23aabcc40;
                          }
                          plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8f3c0);
                          plVar6 = _DAT_23ed8f630;
                          if (plVar7 == (longlong *)0x0) {
                            pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                            plVar6 = *(longlong **)(lVar15 + 0x70);
                            plVar8 = (longlong *)0x0;
                            *(undefined8 *)(lVar15 + 0x70) = 0;
                            uVar20 = 0xe6;
                            uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                            *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23aabcc40;
                          }
                          lVar10 = *(longlong *)(lVar15 + 0x10);
                          plVar9 = *(longlong **)(lVar10 + 0xe20);
                          if (plVar9 == (longlong *)0x0) {
                            plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                          }
                          else {
                            lVar12 = plVar9[3];
                            *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                            *(longlong *)(lVar10 + 0xe20) = lVar12;
                            *plVar9 = 1;
                          }
                          pcVar11 = _PyRuntime_exref;
                          plVar8 = (longlong *)&DAT_23ed6a4c0;
                          plVar9[4] = 0;
                          lVar10 = *(longlong *)
                                    (*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
                          lVar12 = plVar9[-1];
                          puVar17 = *(undefined8 **)(lVar10 + 8);
                          *puVar17 = plVar9 + -2;
                          plVar9[-2] = lVar10;
                          plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                          *(longlong **)(lVar10 + 8) = plVar9 + -2;
                          plVar16 = DAT_23ed6a4c0;
                          *plVar6 = *plVar6 + 1;
                          plVar9[3] = (longlong)plVar6;
                          uVar22 = DAT_23ed6cd28;
                          if (plVar16 == (longlong *)0x0) {
                            plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar16 != (longlong *)0x0) {
                              *plVar16 = *plVar16 + 1;
                              DAT_23ed6a4c0 = plVar16;
                              goto LAB_23aabc7e2;
                            }
                            PyErr_PrintEx(0,0);
                            Py_Exit(1);
LAB_23aabd1b0:
                            plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23ed8f648);
                            if (plVar9 == (longlong *)0x0) {
LAB_23aabd2ec:
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xec;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23aabcc40;
                            }
                            iVar5 = FUN_23a35f020(plVar9);
                            lVar10 = *plVar9 + -1;
                            if (iVar5 == -1) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              *plVar9 = lVar10;
                              if (lVar10 == 0) {
                                FUN_23a334bc0();
                              }
                              uVar20 = 0xec;
                              goto LAB_23aabcc40;
                            }
                            *plVar9 = lVar10;
                            if (lVar10 == 0) {
                              (**(code **)(plVar9[1] + 0x30))();
                            }
                            if (iVar5 == 1) {
                              lVar12 = FUN_23ebc07d0();
                              lVar10 = _DAT_23ed8f650;
                              if (lVar12 == 0) {
                                FUN_23e915740(lVar15,pplStack_230,DAT_23ed8f388);
                                uVar20 = 0xed;
                                pplStack_230 = (longlong **)plStack_218;
                                uStack_228 = uStack_210;
                                plVar6 = plStack_208;
                                goto LAB_23aabcc40;
                              }
                              *(undefined4 *)(plVar2 + 5) = 0xed;
                              plVar6 = (longlong *)
                                       FUN_23e915840(lVar15,lVar12,DAT_23ed8f390,
                                                     *(undefined8 *)(lVar10 + 0x18));
                              if (plVar6 == (longlong *)0x0) {
                                pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                plVar6 = *(longlong **)(lVar15 + 0x70);
                                *(undefined8 *)(lVar15 + 0x70) = 0;
                                uVar20 = 0xed;
                                uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23aabcc40;
                              }
                              *plVar6 = *plVar6 + -1;
                              if (*plVar6 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                              *(undefined4 *)(plVar2 + 5) = 0xee;
                              plVar6 = (longlong *)FUN_23e91bfe0(lVar15,plVar8,_DAT_23ed8f658);
                              if (plVar6 == (longlong *)0x0) {
                                pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                plVar6 = *(longlong **)(lVar15 + 0x70);
                                uVar20 = 0xee;
                                uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(lVar15 + 0x70) = 0;
                                goto LAB_23aabcc40;
                              }
                              *plVar6 = *plVar6 + -1;
                              if (*plVar6 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                            }
LAB_23aabcb90:
                            iVar5 = FUN_23e8be270(lVar15,plVar7,_DAT_23ed8f660);
                            if (iVar5 == -1) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xf0;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23aabcc40;
                            }
                            if ((iVar5 != 0) &&
                               (cVar4 = FUN_23e8d9ac0(plVar7,_DAT_23ed8f660,_Py_FalseStruct_exref),
                               cVar4 == '\0')) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xf1;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23aabcc40;
                            }
LAB_23aabc8d5:
                            *(undefined4 *)(plVar2 + 5) = 0xf4;
                            plVar6 = (longlong *)FUN_23e915840(lVar15,plVar13,DAT_23ed8f668,plVar14)
                            ;
                            if (plVar6 == (longlong *)0x0) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xf4;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              *plVar6 = *plVar6 + -1;
                              if (*plVar6 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                              plVar6 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8f538);
                              if (plVar6 != (longlong *)0x0) {
                                plVar9 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23ed8f540);
                                *plVar6 = *plVar6 + -1;
                                if (*plVar6 == 0) {
                                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                                }
                                if (plVar9 != (longlong *)0x0) {
                                  *(undefined4 *)(plVar2 + 5) = 0xf7;
                                  plVar6 = (longlong *)
                                           FUN_23e915840(lVar15,plVar9,_DAT_23ed8f670,plVar14);
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  if (plVar6 != (longlong *)0x0) {
                                    *plVar6 = *plVar6 + -1;
                                    if (*plVar6 == 0) {
                                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                                    }
                                    lVar10 = *(longlong *)(*(longlong *)(lVar15 + 0x38) + 8);
                                    plVar6 = *(longlong **)(lVar10 + 0x28);
                                    plVar2 = (longlong *)plVar6[2];
                                    *(undefined8 *)(*(longlong *)(lVar15 + 0x38) + 8) =
                                         *(undefined8 *)(lVar10 + 0x30);
                                    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                                    if (plVar2 != (longlong *)0x0) {
                                      plVar6[2] = 0;
                                      *plVar2 = *plVar2 + -1;
                                      if (*plVar2 == 0) {
                                        (**(code **)(plVar2[1] + 0x30))();
                                      }
                                    }
                                    *plVar6 = *plVar6 + -1;
                                    if (*plVar6 == 0) {
                                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                                    }
                                    plVar6[0xf] = 0;
                                    pcVar11 = _Py_NoneStruct_exref;
                                    *(longlong *)_Py_NoneStruct_exref =
                                         *(longlong *)_Py_NoneStruct_exref + 1;
                                    if ((plVar7 != (longlong *)0x0) &&
                                       (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
                                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                                    }
                                    if ((plVar8 != (longlong *)0x0) &&
                                       (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                                    }
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                                    }
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                                      return pcVar11;
                                    }
                                    return pcVar11;
                                  }
                                }
                              }
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xf7;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                            }
                          }
                          else {
LAB_23aabc7e2:
                            pplStack_230 = &plStack_218;
                            uStack_210 = uVar22;
                            plStack_218 = plVar14;
                            lVar10 = FUN_23e94ed00(lVar15,plVar16,pplStack_230);
                            if (lVar10 == 0) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              *plVar7 = *plVar7 + -1;
                              if (*plVar7 == 0) {
                                (**(code **)(plVar7[1] + 0x30))(plVar7);
                              }
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                            }
                            else {
                              plVar9[4] = lVar10;
                              plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              if (plVar6 != (longlong *)0x0) {
                                *(undefined4 *)(plVar2 + 5) = 0xe6;
                                plVar8 = (longlong *)FUN_23e914090(lVar15,plVar7,plVar6);
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                *plVar6 = *plVar6 + -1;
                                if (*plVar6 == 0) {
                                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                                }
                                if (plVar8 == (longlong *)0x0) {
                                  pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                  plVar6 = *(longlong **)(lVar15 + 0x70);
                                  plVar8 = (longlong *)0x0;
                                  *(undefined8 *)(lVar15 + 0x70) = 0;
                                  uVar20 = 0xe6;
                                  uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                  *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                  plVar7 = (longlong *)0x0;
                                  goto LAB_23aabcc40;
                                }
                                *plVar8 = *plVar8 + -1;
                                if (*plVar8 == 0) {
                                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                                }
                                plVar7 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8f558);
                                if (plVar7 == (longlong *)0x0) {
LAB_23aabcfc0:
                                  pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                  plVar6 = *(longlong **)(lVar15 + 0x70);
                                  plVar8 = (longlong *)0x0;
                                  *(undefined8 *)(lVar15 + 0x70) = 0;
                                  uVar20 = 0xe9;
                                  uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                  *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                  plVar7 = (longlong *)0x0;
                                  goto LAB_23aabcc40;
                                }
                                iVar5 = FUN_23a35f020(plVar7);
                                lVar10 = *plVar7 + -1;
                                if (iVar5 == -1) {
                                  pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                  plVar6 = *(longlong **)(lVar15 + 0x70);
                                  *(undefined8 *)(lVar15 + 0x70) = 0;
                                  uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                  *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                  *plVar7 = lVar10;
                                  if (lVar10 == 0) {
                                    plVar8 = (longlong *)0x0;
                                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                                    uVar20 = 0xe9;
                                    plVar7 = (longlong *)0x0;
                                  }
                                  else {
                                    uVar20 = 0xe9;
                                    plVar8 = (longlong *)0x0;
                                    plVar7 = (longlong *)0x0;
                                  }
                                  goto LAB_23aabcc40;
                                }
                                *plVar7 = lVar10;
                                if (lVar10 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                if (iVar5 != 0) {
                                  plVar6 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8f558);
                                  if (plVar6 == (longlong *)0x0) goto LAB_23aabcfc0;
                                  iVar5 = FUN_23e8be270(lVar15,plVar6,_DAT_23ed8f638);
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                                  }
                                  if (iVar5 == -1) {
                                    pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                    plVar6 = *(longlong **)(lVar15 + 0x70);
                                    plVar8 = (longlong *)0x0;
                                    *(undefined8 *)(lVar15 + 0x70) = 0;
                                    uVar20 = 0xe9;
                                    uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                    *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                    plVar7 = (longlong *)0x0;
                                    goto LAB_23aabcc40;
                                  }
                                  if (iVar5 != 0) {
                                    plVar6 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8f558);
                                    if (plVar6 == (longlong *)0x0) {
                                      pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                      plVar6 = *(longlong **)(lVar15 + 0x70);
                                      *(undefined8 *)(lVar15 + 0x70) = 0;
                                      uVar20 = 0xea;
                                      uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                      plVar8 = (longlong *)0x0;
                                      plVar7 = (longlong *)0x0;
                                      goto LAB_23aabcc40;
                                    }
                                    plVar7 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23ed8f638);
                                    *plVar6 = *plVar6 + -1;
                                    if (*plVar6 == 0) {
                                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                                    }
                                    if (plVar7 == (longlong *)0x0) {
                                      pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                      plVar6 = *(longlong **)(lVar15 + 0x70);
                                      plVar8 = (longlong *)0x0;
                                      *(undefined8 *)(lVar15 + 0x70) = 0;
                                      uVar20 = 0xea;
                                      uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                      goto LAB_23aabcc40;
                                    }
                                    plVar8 = (longlong *)
                                             FUN_23e8bbbe0(lVar15,plVar7,_DAT_23ed8f640,
                                                           _Py_NoneStruct_exref);
                                    if (plVar8 == (longlong *)0x0) {
                                      pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                      plVar6 = *(longlong **)(lVar15 + 0x70);
                                      uVar20 = 0xeb;
                                      *(undefined8 *)(lVar15 + 0x70) = 0;
                                      uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                      goto LAB_23aabcc40;
                                    }
                                    iVar5 = FUN_23a35f020(plVar8);
                                    if (iVar5 != -1) {
                                      if (iVar5 != 0) goto LAB_23aabd1b0;
                                      goto LAB_23aabcb90;
                                    }
                                    goto LAB_23aabd2ec;
                                  }
                                }
                                plVar8 = (longlong *)0x0;
                                plVar7 = (longlong *)0x0;
                                goto LAB_23aabc8d5;
                              }
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              *plVar7 = *plVar7 + -1;
                              plVar8 = (longlong *)0x0;
                              if (*plVar7 == 0) {
                                (**(code **)(plVar7[1] + 0x30))(plVar7);
                                uVar20 = 0xe6;
                                plVar7 = (longlong *)0x0;
                                goto LAB_23aabcc40;
                              }
                            }
                            plVar8 = (longlong *)0x0;
                            uVar20 = 0xe6;
                            plVar7 = (longlong *)0x0;
                          }
LAB_23aabcc40:
                          plVar9 = DAT_23ed6a4f8;
                          if (plVar6 == (longlong *)0x0) {
                            if (DAT_23ed6a4f8 == (longlong *)0x0) {
                              plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                            }
                            else {
                              plVar6 = (longlong *)*DAT_23ed6a4f8;
                              *DAT_23ed6a4f8 = 1;
                              DAT_23ed6a4f8 = plVar6;
                              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                            }
                            pcVar11 = _PyRuntime_exref;
                            plVar9[2] = 0;
                            plVar9[3] = (longlong)plVar2;
                            *plVar2 = *plVar2 + 1;
                            lVar10 = *(longlong *)(pcVar11 + 0x1f8);
                            *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
                            lVar10 = *(longlong *)(lVar10 + 0x10);
                            *(undefined4 *)(plVar9 + 4) = 0xffffffff;
                            lVar10 = *(longlong *)(lVar10 + 0x2e8);
                            lVar12 = plVar9[-1];
                            puVar17 = *(undefined8 **)(lVar10 + 8);
                            *puVar17 = plVar9 + -2;
                            plVar9[-2] = lVar10;
                            plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                            *(longlong **)(lVar10 + 8) = plVar9 + -2;
                            plVar16 = plVar9;
                          }
                          else {
                            plVar16 = plVar6;
                            if ((longlong *)plVar6[3] != plVar2) {
                              if (DAT_23ed6a4f8 == (longlong *)0x0) {
                                plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                              }
                              else {
                                plVar16 = (longlong *)*DAT_23ed6a4f8;
                                *DAT_23ed6a4f8 = 1;
                                DAT_23ed6a4f8 = plVar16;
                                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                              }
                              plVar9[3] = (longlong)plVar2;
                              *plVar2 = *plVar2 + 1;
                              *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
                              pcVar11 = _PyRuntime_exref;
                              *(undefined4 *)(plVar9 + 4) = 0xffffffff;
                              lVar10 = *(longlong *)
                                        (*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) +
                                        0x2e8);
                              lVar12 = plVar9[-1];
                              puVar17 = *(undefined8 **)(lVar10 + 8);
                              *puVar17 = plVar9 + -2;
                              plVar9[-2] = lVar10;
                              plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                              lVar12 = *plVar6;
                              *(longlong **)(lVar10 + 8) = plVar9 + -2;
                              plVar9[2] = (longlong)plVar6;
                              plVar16 = plVar9;
                              if (lVar12 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                            }
                          }
                          FUN_23e8bba40(plVar2,&DAT_23ec31985,plVar13,plVar14,plVar7,plVar8);
                          if (_DAT_23ed90a90 == plVar2) {
                            *plVar2 = *plVar2 + -1;
                            if (*plVar2 == 0) {
                              (**(code **)(plVar2[1] + 0x30))(plVar2);
                            }
                            _DAT_23ed90a90 = (longlong *)0x0;
                          }
                          lVar10 = *(longlong *)(*(longlong *)(lVar15 + 0x38) + 8);
                          plVar6 = *(longlong **)(lVar10 + 0x28);
                          plVar2 = (longlong *)plVar6[2];
                          *(undefined8 *)(*(longlong *)(lVar15 + 0x38) + 8) =
                               *(undefined8 *)(lVar10 + 0x30);
                          *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                          if (plVar2 != (longlong *)0x0) {
                            plVar6[2] = 0;
                            *plVar2 = *plVar2 + -1;
                            if (*plVar2 == 0) {
                              (**(code **)(plVar2[1] + 0x30))();
                            }
                          }
                          *plVar6 = *plVar6 + -1;
                          if (*plVar6 == 0) {
                            (**(code **)(plVar6[1] + 0x30))(plVar6);
                          }
                          plVar6[0xf] = 0;
                          if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0))
                          {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0))
                          {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          FUN_23a33aa70(lVar15,pplStack_230,uStack_228,plVar16);
                          return (code *)0x0;
                        }
                        *plVar13 = *plVar13 + 1;
                        DAT_23ed6a4c0 = plVar13;
                      }
                      pplStack_158 = &plStack_140;
                      uStack_138 = uVar22;
                      puStack_1a8 = (undefined8 *)0x23aabb83b;
                      plStack_140 = plVar7;
                      lVar15 = FUN_23e94ed00(lVar10,DAT_23ed6a4c0,pplStack_158);
                      if (lVar15 != 0) {
                        lVar12 = *(longlong *)(lVar10 + 0x10);
                        plVar13 = *(longlong **)(lVar12 + 0xe20);
                        if (plVar13 == (longlong *)0x0) {
                          puStack_1a8 = (undefined8 *)0x23aabc099;
                          plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                        }
                        else {
                          lVar1 = plVar13[3];
                          *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                          *(longlong *)(lVar12 + 0xe20) = lVar1;
                          *plVar13 = 1;
                        }
                        lVar12 = *(longlong *)
                                  (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                                  0x2e8);
                        lVar1 = plVar13[-1];
                        puVar17 = *(undefined8 **)(lVar12 + 8);
                        *puVar17 = plVar13 + -2;
                        plVar9 = DAT_23ed8f5d8;
                        plVar13[-2] = lVar12;
                        plVar13[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar17;
                        *(longlong **)(lVar12 + 8) = plVar13 + -2;
                        plVar13[3] = lVar15;
                        *plVar9 = *plVar9 + 1;
                        plVar13[4] = (longlong)plVar9;
                        puStack_1a8 = (undefined8 *)0x23aabb8e7;
                        plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          puStack_1a8 = (undefined8 *)0x23aabb8fc;
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (plVar9 != (longlong *)0x0) {
                          *(undefined4 *)(plVar2 + 5) = 0xcb;
                          puStack_1a8 = (undefined8 *)0x23aabb91a;
                          plVar13 = (longlong *)FUN_23e914090(lVar10,plVar16,plVar9);
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            puStack_1a8 = (undefined8 *)0x23aabb92e;
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                          }
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            puStack_1a8 = (undefined8 *)0x23aabb93e;
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          if (plVar13 == (longlong *)0x0) {
                            plStack_150 = *(longlong **)(lVar10 + 0x60);
                            plVar13 = *(longlong **)(lVar10 + 0x70);
                            plVar9 = (longlong *)0x0;
                            *(undefined8 *)(lVar10 + 0x70) = 0;
                            plVar14 = (longlong *)0x0;
                            uVar20 = 0xcb;
                            pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                            plVar16 = DAT_23ed6a4f8;
                            plVar3 = uStack_148;
                            goto joined_r0x00023aabbaf3;
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            puStack_1a8 = (undefined8 *)0x23aabb959;
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          puStack_1a8 = (undefined8 *)0x23aabb968;
                          plVar16 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8f5e0);
                          if (plVar16 == (longlong *)0x0) {
                            plStack_150 = *(longlong **)(lVar10 + 0x60);
                            plVar13 = *(longlong **)(lVar10 + 0x70);
                            plVar14 = (longlong *)0x0;
                            *(undefined8 *)(lVar10 + 0x70) = 0;
                            uVar20 = 0xd1;
                            pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                            plVar9 = (longlong *)0x0;
                            plVar16 = DAT_23ed6a4f8;
                            plVar3 = uStack_148;
                            goto joined_r0x00023aabbaf3;
                          }
                          puStack_1a8 = (undefined8 *)0x23aabb979;
                          lVar15 = FUN_23ebc0680();
                          if (lVar15 == 0) {
                            puStack_1a8 = (undefined8 *)0x23aabc511;
                            FUN_23e915740(lVar10,pplStack_158,DAT_23ed8f590);
                            *plVar16 = *plVar16 + -1;
                            lVar15 = *plVar16;
                            plStack_150 = plStack_140;
                            pplStack_158 = (longlong **)uStack_138;
                            plVar13 = plStack_130;
                          }
                          else {
                            puStack_1a8 = (undefined8 *)0x23aabb994;
                            plVar13 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23ed8f5e8);
                            if (plVar13 != (longlong *)0x0) {
                              puStack_1a8 = (undefined8 *)0x23aabb9af;
                              plVar9 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8f5f0);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aabb9c2;
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              if (plVar9 == (longlong *)0x0) {
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  plVar14 = (longlong *)0x0;
                                  plVar9 = (longlong *)0x0;
                                  puStack_1a8 = (undefined8 *)0x23aabc579;
                                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                                  uVar20 = 0xd1;
                                  plVar16 = DAT_23ed6a4f8;
                                  plVar3 = uStack_148;
                                }
                                else {
                                  plVar9 = (longlong *)0x0;
                                  plVar14 = (longlong *)0x0;
                                  uVar20 = 0xd1;
                                  plVar16 = DAT_23ed6a4f8;
                                  plVar3 = uStack_148;
                                }
                                goto joined_r0x00023aabbaf3;
                              }
                              *(undefined4 *)(plVar2 + 5) = 0xd1;
                              puStack_1a8 = (undefined8 *)0x23aabb9e0;
                              plVar13 = (longlong *)FUN_23e914090(lVar10,plVar16,plVar9);
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aabb9f4;
                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                              }
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aabba06;
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              if (plVar13 == (longlong *)0x0) {
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                plVar9 = (longlong *)0x0;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                uVar20 = 0xd1;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                plVar14 = (longlong *)0x0;
                                plVar16 = DAT_23ed6a4f8;
                                plVar3 = uStack_148;
                                goto joined_r0x00023aabbaf3;
                              }
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aabba1f;
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              *(undefined4 *)(plVar2 + 5) = 0xd2;
                              puStack_1a8 = (undefined8 *)0x23aabba38;
                              plVar13 = (longlong *)FUN_23e91bfe0(lVar10,plVar8,DAT_23ed8f5f8);
                              if (plVar13 == (longlong *)0x0) {
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                plVar9 = (longlong *)0x0;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                uVar20 = 0xd2;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                plVar14 = (longlong *)0x0;
                                plVar16 = DAT_23ed6a4f8;
                                plVar3 = uStack_148;
                                goto joined_r0x00023aabbaf3;
                              }
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aabba58;
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              goto LAB_23aabb3d2;
                            }
                            plStack_150 = *(longlong **)(lVar10 + 0x60);
                            plVar13 = *(longlong **)(lVar10 + 0x70);
                            *(undefined8 *)(lVar10 + 0x70) = 0;
                            pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                            *plVar16 = *plVar16 + -1;
                            lVar15 = *plVar16;
                          }
                          if (lVar15 == 0) {
                            plVar14 = (longlong *)0x0;
                            plVar9 = (longlong *)0x0;
                            puStack_1a8 = (undefined8 *)0x23aabc4f3;
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                            uVar20 = 0xd1;
                            plVar16 = DAT_23ed6a4f8;
                            plVar3 = uStack_148;
                          }
                          else {
                            plVar14 = (longlong *)0x0;
                            plVar9 = (longlong *)0x0;
                            uVar20 = 0xd1;
                            plVar16 = DAT_23ed6a4f8;
                            plVar3 = uStack_148;
                          }
                          goto joined_r0x00023aabbaf3;
                        }
                      }
                      plVar14 = (longlong *)0x0;
                      plStack_150 = *(longlong **)(lVar10 + 0x60);
                      plVar13 = *(longlong **)(lVar10 + 0x70);
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        plVar9 = (longlong *)0x0;
                        puStack_1a8 = (undefined8 *)0x23aabc2bd;
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                        uVar20 = 0xcc;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                      }
                      else {
                        plVar9 = (longlong *)0x0;
                        uVar20 = 0xcc;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                      }
                      goto joined_r0x00023aabbaf3;
                    }
                    plStack_150 = *(longlong **)(lVar10 + 0x60);
                    plVar13 = *(longlong **)(lVar10 + 0x70);
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    *plVar16 = *plVar16 + -1;
                    lVar15 = *plVar16;
                  }
                  if (lVar15 == 0) {
                    plVar14 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    puStack_1a8 = (undefined8 *)0x23aabc1e1;
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                    uVar20 = 200;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                  }
                  else {
                    plVar14 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    uVar20 = 200;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                  }
                  goto joined_r0x00023aabbaf3;
                }
LAB_23aabb3d2:
                lVar15 = *(longlong *)(DAT_23ed8f338 + 0x20);
                if (*(char *)(lVar15 + 10) == '\0') {
                  puStack_1a8 = (undefined8 *)0x23aabbcec;
                  plVar13 = (longlong *)FUN_23a37a020(DAT_23ed8f338,DAT_23ed8f600);
                  if (plVar13 == (longlong *)0x0) goto LAB_23aabba89;
                  lVar12 = *plVar13;
LAB_23aabbcf8:
                  if (lVar12 == 0) goto LAB_23aabba89;
                }
                else {
                  iVar5 = *(int *)(lVar15 + 0xc);
                  if (*(int *)(lVar15 + 0xc) == 0) {
                    *(int *)(lVar15 + 0xc) = DAT_23ec10790;
                    iVar5 = DAT_23ec10790;
                    DAT_23ec10790 = DAT_23ec10790 + 1;
                  }
                  if (DAT_23ec1076c != iVar5) {
                    puStack_1a8 = (undefined8 *)0x23aabba79;
                    DAT_23ec1076c = iVar5;
                    DAT_23ed90a98 =
                         FUN_23e8cbd60(lVar15,DAT_23ed8f600,*(undefined8 *)(DAT_23ed8f600 + 0x18));
                  }
                  if (-1 < DAT_23ed90a98) {
                    lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
                    lVar12 = *(longlong *)(lVar1 + 8 + DAT_23ed90a98 * 0x10);
                    if (lVar12 != 0) goto LAB_23aabb43f;
                    puStack_1a8 = (undefined8 *)0x23aabc123;
                    DAT_23ed90a98 =
                         FUN_23e8cbd60(lVar15,DAT_23ed8f600,*(undefined8 *)(DAT_23ed8f600 + 0x18));
                    if (-1 < DAT_23ed90a98) {
                      lVar12 = *(longlong *)(lVar1 + 8 + DAT_23ed90a98 * 0x10);
                      goto LAB_23aabbcf8;
                    }
                  }
LAB_23aabba89:
                  puStack_1a8 = (undefined8 *)0x23aabba9f;
                  plVar13 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed8f600);
                  if ((plVar13 == (longlong *)0x0) || (lVar12 = *plVar13, lVar12 == 0)) {
                    plVar9 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                    puStack_1a8 = (undefined8 *)0x23aabbac9;
                    FUN_23e915740(lVar10,&plStack_140,DAT_23ed8f600);
                    uVar20 = 0xd5;
                    plVar13 = plStack_130;
                    plVar16 = DAT_23ed6a4f8;
                    pplStack_158 = (longlong **)uStack_138;
                    plStack_150 = plStack_140;
                    plVar3 = uStack_148;
                    goto joined_r0x00023aabbaf3;
                  }
                }
LAB_23aabb43f:
                puStack_1a8 = (undefined8 *)0x23aabb44e;
                plVar13 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23ed8f528);
                if (plVar13 == (longlong *)0x0) {
                  plStack_150 = *(longlong **)(lVar10 + 0x60);
                  plVar13 = *(longlong **)(lVar10 + 0x70);
                  plVar14 = (longlong *)0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  uVar20 = 0xd5;
                  pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  plVar9 = (longlong *)0x0;
                  plVar16 = DAT_23ed6a4f8;
                  plVar3 = uStack_148;
                }
                else {
                  *(undefined4 *)(plVar2 + 5) = 0xd5;
                  puStack_1a8 = (undefined8 *)0x23aabb46f;
                  plVar14 = (longlong *)FUN_23e914090(lVar10,lVar12,plVar13);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    puStack_1a8 = (undefined8 *)0x23aabbcba;
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (plVar14 == (longlong *)0x0) {
                    plStack_150 = *(longlong **)(lVar10 + 0x60);
                    plVar13 = *(longlong **)(lVar10 + 0x70);
                    plVar9 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uVar20 = 0xd5;
                    pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                  }
                  else {
                    *(undefined4 *)(plVar2 + 5) = 0xd6;
                    puStack_1a8 = (undefined8 *)0x23aabb49f;
                    plVar9 = (longlong *)FUN_23e91bfe0(lVar10,plVar14,DAT_23ed8f5f8);
                    if (plVar9 == (longlong *)0x0) {
                      plStack_150 = *(longlong **)(lVar10 + 0x60);
                      plVar13 = *(longlong **)(lVar10 + 0x70);
                      uVar20 = 0xd6;
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      plVar16 = DAT_23ed6a4f8;
                      plVar3 = uStack_148;
                    }
                    else {
                      puStack_1a8 = (undefined8 *)0x23aabb4ba;
                      plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23ed8f608);
                      if (plVar13 != (longlong *)0x0) {
                        puStack_1a8 = (undefined8 *)0x23aabb4d5;
                        pplStack_158 = (longlong **)FUN_23e8bc2f0(plVar13,DAT_23ed8f610);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          puStack_1a8 = (undefined8 *)0x23aabbcd0;
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (pplStack_158 != (longlong **)0x0) {
                          puStack_1a8 = (undefined8 *)0x23aabb4fc;
                          iVar5 = FUN_23e912620(plVar9,pplStack_158);
                          *pplStack_158 = (longlong *)((longlong)*pplStack_158 + -1);
                          if (*pplStack_158 == (longlong *)0x0) {
                            puStack_1a8 = (undefined8 *)0x23aabb514;
                            (**(code **)((longlong)pplStack_158[1] + 0x30))(pplStack_158);
                          }
                          if (iVar5 != -1) {
                            if (iVar5 == 1) {
                              puStack_1a8 = (undefined8 *)0x23aabbf25;
                              lVar12 = FUN_23ebc07d0();
                              lVar15 = DAT_23ed8f618;
                              if (lVar12 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aabc497;
                                FUN_23e915740(lVar10,&plStack_140,DAT_23ed8f388);
                                uVar20 = 0xd9;
                                plVar13 = plStack_130;
                                plVar16 = DAT_23ed6a4f8;
                                pplStack_158 = (longlong **)uStack_138;
                                plStack_150 = plStack_140;
                                plVar3 = uStack_148;
                              }
                              else {
                                *(undefined4 *)(plVar2 + 5) = 0xd9;
                                puStack_1a8 = (undefined8 *)0x23aabbf52;
                                plVar13 = (longlong *)
                                          FUN_23e915840(lVar10,lVar12,DAT_23ed8f390,
                                                        *(undefined8 *)(lVar15 + 0x18));
                                if (plVar13 != (longlong *)0x0) {
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aabbf6b;
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  pcVar11 = _Py_TrueStruct_exref;
                                  *(longlong *)_Py_TrueStruct_exref =
                                       *(longlong *)_Py_TrueStruct_exref + 1;
                                  goto LAB_23aabb57b;
                                }
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                uVar20 = 0xd9;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                plVar16 = DAT_23ed6a4f8;
                                plVar3 = uStack_148;
                              }
                            }
                            else {
                              puStack_1a8 = (undefined8 *)0x23aabb52d;
                              lVar12 = FUN_23ebc07d0();
                              lVar15 = DAT_23ed8f620;
                              if (lVar12 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aabc34c;
                                FUN_23e915740(lVar10,&plStack_140,DAT_23ed8f388);
                                uVar20 = 0xdc;
                                plVar13 = plStack_130;
                                plVar16 = DAT_23ed6a4f8;
                                pplStack_158 = (longlong **)uStack_138;
                                plStack_150 = plStack_140;
                                plVar3 = uStack_148;
                              }
                              else {
                                *(undefined4 *)(plVar2 + 5) = 0xdc;
                                puStack_1a8 = (undefined8 *)0x23aabb55a;
                                plVar13 = (longlong *)
                                          FUN_23e915840(lVar10,lVar12,DAT_23ed8f390,
                                                        *(undefined8 *)(lVar15 + 0x18));
                                if (plVar13 != (longlong *)0x0) {
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aabc027;
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  pcVar11 = _Py_FalseStruct_exref;
                                  *(longlong *)_Py_FalseStruct_exref =
                                       *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23aabb57b:
                                  lVar15 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
                                  plVar13 = *(longlong **)(lVar15 + 0x28);
                                  plVar2 = (longlong *)plVar13[2];
                                  *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) =
                                       *(undefined8 *)(lVar15 + 0x30);
                                  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
                                  if (plVar2 != (longlong *)0x0) {
                                    plVar13[2] = 0;
                                    *plVar2 = *plVar2 + -1;
                                    if (*plVar2 == 0) {
                                      puStack_1a8 = (undefined8 *)0x23aabc007;
                                      (**(code **)(plVar2[1] + 0x30))();
                                    }
                                  }
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aabb5c1;
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  plVar13[0xf] = 0;
                                  if ((plVar8 != (longlong *)0x0) &&
                                     (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                                    puStack_1a8 = (undefined8 *)0x23aabbffa;
                                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                                  }
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aabb5e8;
                                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                                  }
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aabb5f9;
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aabb609;
                                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                                  }
                                  *plVar7 = *plVar7 + -1;
                                  if (*plVar7 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aabb61a;
                                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                                    return pcVar11;
                                  }
                                  return pcVar11;
                                }
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                uVar20 = 0xdc;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                plVar16 = DAT_23ed6a4f8;
                                plVar3 = uStack_148;
                              }
                            }
                            goto joined_r0x00023aabbaf3;
                          }
                        }
                      }
                      plStack_150 = *(longlong **)(lVar10 + 0x60);
                      plVar13 = *(longlong **)(lVar10 + 0x70);
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      uVar20 = 0xd8;
                      pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      plVar16 = DAT_23ed6a4f8;
                      plVar3 = uStack_148;
                    }
                  }
                }
joined_r0x00023aabbaf3:
                uStack_148._4_4_ = (undefined4)((ulonglong)plVar3 >> 0x20);
                DAT_23ed6a4f8 = plVar16;
                uStack_148 = plVar3;
                if (plVar13 == (longlong *)0x0) {
                  if (plVar16 == (longlong *)0x0) {
                    uStack_148 = (longlong *)CONCAT44(uStack_148._4_4_,uVar20);
                    puStack_1a8 = (undefined8 *)0x23aabc158;
                    plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                    uVar20 = SUB84(uStack_148,0);
                  }
                  else {
                    DAT_23ed6a4f8 = (longlong *)*plVar16;
                    *plVar16 = 1;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  pcVar11 = _PyRuntime_exref;
                  plVar16[3] = (longlong)plVar2;
                  plVar16[2] = 0;
                  *plVar2 = *plVar2 + 1;
                  lVar15 = *(longlong *)(pcVar11 + 0x1f8);
                  *(undefined4 *)((longlong)plVar16 + 0x24) = uVar20;
                  *(undefined4 *)(plVar16 + 4) = 0xffffffff;
                  lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
                  lVar12 = plVar16[-1];
                  puVar17 = *(undefined8 **)(lVar15 + 8);
                  *puVar17 = plVar16 + -2;
                  plVar16[-2] = lVar15;
                  plVar16[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                  *(longlong **)(lVar15 + 8) = plVar16 + -2;
                  plVar18 = plVar16;
                  plVar3 = uStack_148;
                }
                else {
                  plVar18 = plVar13;
                  if ((longlong *)plVar13[3] != plVar2) {
                    if (plVar16 == (longlong *)0x0) {
                      uStack_148 = (longlong *)CONCAT44(uStack_148._4_4_,uVar20);
                      puStack_1a8 = (undefined8 *)0x23aabbf10;
                      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                      uVar20 = SUB84(uStack_148,0);
                    }
                    else {
                      DAT_23ed6a4f8 = (longlong *)*plVar16;
                      *plVar16 = 1;
                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                    }
                    plVar16[3] = (longlong)plVar2;
                    *plVar2 = *plVar2 + 1;
                    *(undefined4 *)((longlong)plVar16 + 0x24) = uVar20;
                    pcVar11 = _PyRuntime_exref;
                    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
                    lVar15 = *(longlong *)
                              (*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
                    lVar12 = plVar16[-1];
                    puVar17 = *(undefined8 **)(lVar15 + 8);
                    *puVar17 = plVar16 + -2;
                    plVar16[-2] = lVar15;
                    plVar16[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                    lVar12 = *plVar13;
                    *(longlong **)(lVar15 + 8) = plVar16 + -2;
                    plVar16[2] = (longlong)plVar13;
                    plVar18 = plVar16;
                    plVar3 = uStack_148;
                    if (lVar12 == 0) {
                      puStack_1a8 = (undefined8 *)0x23aabbb9f;
                      uStack_148 = plVar16;
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                      plVar18 = uStack_148;
                      plVar3 = uStack_148;
                    }
                  }
                }
                uStack_148 = plVar3;
                puStack_1a8 = (undefined8 *)0x23aabbbcb;
                plStack_180 = plVar8;
                plStack_178 = plVar14;
                plStack_170 = plVar9;
                FUN_23e8bba40(plVar2,"ooooo",plVar6,plVar7);
                if (DAT_23ed90aa8 == plVar2) {
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    puStack_1a8 = (undefined8 *)0x23aabbe00;
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                  }
                  DAT_23ed90aa8 = (longlong *)0x0;
                }
                lVar15 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
                plVar13 = *(longlong **)(lVar15 + 0x28);
                plVar2 = (longlong *)plVar13[2];
                *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
                *(undefined4 *)(plVar13 + 8) = 0xffffffff;
                if (plVar2 != (longlong *)0x0) {
                  plVar13[2] = 0;
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    puStack_1a8 = (undefined8 *)0x23aabbc11;
                    (**(code **)(plVar2[1] + 0x30))();
                  }
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  puStack_1a8 = (undefined8 *)0x23aabbc21;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                plVar13[0xf] = 0;
                if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                  puStack_1a8 = (undefined8 *)0x23aabbc3e;
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  puStack_1a8 = (undefined8 *)0x23aabbc53;
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                  puStack_1a8 = (undefined8 *)0x23aabbc69;
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                *plVar6 = *plVar6 + -1;
                if (*plVar6 == 0) {
                  puStack_1a8 = (undefined8 *)0x23aabbc79;
                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  puStack_1a8 = (undefined8 *)0x23aabbc8a;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                puStack_1a8 = (undefined8 *)0x23aabbca1;
                FUN_23a33aa70(lVar10,plStack_150,pplStack_158,plVar18);
                return (code *)0x0;
              }
              *plVar6 = *plVar6 + 1;
              DAT_23ed6a4c0 = plVar6;
            }
            uStack_80 = uVar22;
            puStack_d0 = (undefined8 *)0x23aaba72f;
            local_88 = plVar9;
            lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
            if (lVar10 == 0) {
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)local_90 = *(longlong *)local_90 + -1;
              if (*(longlong *)local_90 == 0) {
                puStack_d0 = (undefined8 *)0x23aabb033;
                (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                uVar20 = 0xb1;
                puStack_d0 = (undefined8 *)0x23aabb04f;
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              else {
                uVar20 = 0xb1;
              }
              goto LAB_23aaba82d;
            }
            plVar14[4] = lVar10;
            puStack_d0 = (undefined8 *)0x23aaba754;
            plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              puStack_d0 = (undefined8 *)0x23aabaebb;
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar6 == (longlong *)0x0) {
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar19 = 0xb1;
              uVar20 = 0xb1;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)local_90 = *(longlong *)local_90 + -1;
              lVar10 = *(longlong *)local_90;
              goto joined_r0x00023aabb1fd;
            }
            *(undefined4 *)(plVar2 + 5) = 0xb1;
            puStack_d0 = (undefined8 *)0x23aaba78a;
            plVar7 = (longlong *)FUN_23e914090(param_1,local_90,plVar6);
            *(longlong *)local_90 = *(longlong *)local_90 + -1;
            if (*(longlong *)local_90 == 0) {
              puStack_d0 = (undefined8 *)0x23aaba7a2;
              (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
            }
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              puStack_d0 = (undefined8 *)0x23aabaf0a;
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            if (plVar7 != (longlong *)0x0) {
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                puStack_d0 = (undefined8 *)0x23aaba7c7;
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              pcVar11 = _Py_TrueStruct_exref;
              *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
LAB_23aabacd7:
              lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar6 = *(longlong **)(lVar10 + 0x28);
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
              plVar2 = (longlong *)plVar6[2];
              *(undefined4 *)(plVar6 + 8) = 0xffffffff;
              local_90 = pcVar11;
              if (plVar2 != (longlong *)0x0) {
                plVar6[2] = 0;
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  puStack_d0 = (undefined8 *)0x23aabaeec;
                  (**(code **)(plVar2[1] + 0x30))();
                }
              }
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                puStack_d0 = (undefined8 *)0x23aabad22;
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              plVar6[0xf] = 0;
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                puStack_d0 = (undefined8 *)0x23aabad44;
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                puStack_d0 = (undefined8 *)0x23aabad5f;
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                puStack_d0 = (undefined8 *)0x23aabad7e;
                (**(code **)(plVar13[1] + 0x30))(plVar13);
                return local_90;
              }
              return local_90;
            }
          }
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar20 = 0xb1;
        }
        goto LAB_23aaba82d;
      }
    }
LAB_23aabaa80:
    plVar7 = local_68;
    uVar22 = local_78._0_8_;
    uVar21 = local_78._8_8_;
    local_68 = (longlong *)0x0;
    local_78 = (undefined1  [16])0x0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      puStack_d0 = (undefined8 *)0x23aabab2b;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    local_68 = (longlong *)0x0;
    local_78 = (undefined1  [16])0x0;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      puStack_d0 = (undefined8 *)0x23aabaacb;
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      puStack_d0 = (undefined8 *)0x23aabaae9;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
  }
  uVar20 = 0xae;
  plVar9 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  local_78._8_8_ = uVar21;
  local_78._0_8_ = uVar22;
  local_68 = plVar7;
LAB_23aaba82d:
  plVar7 = local_68;
  plVar6 = DAT_23ed6a4f8;
  if (local_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      puStack_d0 = (undefined8 *)0x23aabafec;
      plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar6[3] = (longlong)plVar2;
    plVar6[2] = 0;
    *plVar2 = *plVar2 + 1;
    lVar10 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)(plVar6 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)((longlong)plVar6 + 0x24) = uVar20;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar15 = plVar6[-1];
    puVar17 = *(undefined8 **)(lVar10 + 8);
    *puVar17 = plVar6 + -2;
    plVar6[-2] = lVar10;
    plVar6[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar10 + 8) = plVar6 + -2;
    plVar7 = plVar6;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      puStack_d0 = (undefined8 *)0x23aabae81;
      (**(code **)(local_68[1] + 0x30))(local_68);
    }
  }
  else if ((longlong *)local_68[3] != plVar2) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      puStack_d0 = (undefined8 *)0x23aabae9c;
      plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar6[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar10 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)((longlong)plVar6 + 0x24) = uVar20;
    *(undefined4 *)(plVar6 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar15 = plVar6[-1];
    puVar17 = *(undefined8 **)(lVar10 + 8);
    *puVar17 = plVar6 + -2;
    plVar6[-2] = lVar10;
    plVar6[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar10 + 8) = plVar6 + -2;
    plVar6[2] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    plVar7 = plVar6;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      puStack_d0 = (undefined8 *)0x23aabad97;
      (**(code **)(local_68[1] + 0x30))();
    }
  }
  local_68 = plVar7;
  puStack_d0 = (undefined8 *)0x23aaba905;
  local_a8 = plVar9;
  FUN_23e8bba40(plVar2,&DAT_23ec31911,plVar13,plVar8);
  if (DAT_23ed90ab8 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      puStack_d0 = (undefined8 *)0x23aabab00;
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    DAT_23ed90ab8 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar10 + 0x28);
  plVar2 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      puStack_d0 = (undefined8 *)0x23aaba94b;
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    puStack_d0 = (undefined8 *)0x23aaba95b;
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar2 = local_68;
  plVar6[0xf] = 0;
  uVar22 = local_78._0_8_;
  uVar21 = local_78._8_8_;
  local_78 = (undefined1  [16])0x0;
  local_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    puStack_d0 = (undefined8 *)0x23aaba995;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    puStack_d0 = (undefined8 *)0x23aaba9ab;
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar13 = *plVar13 + -1;
  local_68 = plVar2;
  local_78._0_8_ = uVar22;
  local_78._8_8_ = uVar21;
  if (*plVar13 == 0) {
    puStack_d0 = (undefined8 *)0x23aabaa3a;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  puStack_d0 = (undefined8 *)0x23aaba9d4;
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68);
  return (code *)0x0;
}
