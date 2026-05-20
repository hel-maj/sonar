/* ===== 23e74bd70 workers.fishing.fishing_bot:FishingBot._run_casting_module ===== */
/* ghidra_name=FUN_23e74bd70 entry=23e74bd70 size=20278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e74bd70(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong lVar15;
  longlong *plVar16;
  code *pcVar17;
  code *pcVar18;
  longlong *plVar19;
  code *pcVar20;
  undefined4 uVar21;
  longlong lVar22;
  undefined8 *puVar23;
  longlong *in_R10;
  undefined1 auVar24 [8];
  longlong *plVar25;
  code *pcStack_190;
  longlong *plStack_188;
  code *pcStack_180;
  longlong *plStack_178;
  code *pcStack_170;
  longlong *plStack_168;
  longlong *plStack_160;
  longlong *plStack_158;
  longlong *plStack_150;
  longlong *plStack_148;
  longlong *plStack_140;
  longlong *plStack_138;
  code *pcStack_130;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  longlong *plStack_100;
  code *pcStack_f8;
  code *pcStack_f0;
  longlong *plStack_e0;
  longlong *plStack_c0;
  longlong *plStack_b8;
  longlong *plStack_b0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [8];
  code *pcStack_90;
  code *apcStack_88 [2];
  undefined1 auStack_78 [16];
  code *apcStack_68 [5];
  
  plVar7 = _DAT_23eedae38;
  plVar25 = (longlong *)*param_3;
  apcStack_88[0] = (code *)0x0;
  auStack_98 = (undefined1  [8])0x0;
  pcStack_90 = (code *)0x0;
  if (_DAT_23eedae38 == (longlong *)0x0) {
LAB_23e74bdcd:
    _DAT_23eedae38 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf00,DAT_23eedaeb8,0x98);
  }
  else {
    lVar12 = *_DAT_23eedae38;
    if (1 < lVar12) {
      *_DAT_23eedae38 = lVar12 + -1;
      goto LAB_23e74bdcd;
    }
    if (_DAT_23eedae38[2] != 0) {
      *_DAT_23eedae38 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e74bdcd;
    }
  }
  plVar1 = _DAT_23eedae38;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eedae38 + 9;
  lVar15 = *(longlong *)(lVar12 + 8);
  _DAT_23eedae38[0xf] = lVar15;
  *(longlong **)(lVar12 + 8) = plVar7;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar1[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar1[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar12 = _DAT_23eed9138;
  *plVar1 = *plVar1 + 1;
  *(undefined4 *)(plVar1 + 8) = 0;
  uVar3 = DAT_23eed8b40;
  *(undefined4 *)(plVar1 + 5) = 0x2ed;
  plVar7 = (longlong *)FUN_23e915840(param_1,plVar25,uVar3,*(undefined8 *)(lVar12 + 0x18));
  if (plVar7 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_90 = *(code **)(param_1 + 0x68);
    apcStack_88[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (apcStack_88[0] != (code *)0x0) {
      if (*(longlong **)(apcStack_88[0] + 0x18) != plVar1) {
        pcVar17 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        in_R10 = (longlong *)&DAT_23ed6a4f8;
        iVar5 = 0x2ed;
        plStack_140 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_158 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        pcStack_180 = (code *)0x0;
        pcStack_170 = (code *)0x0;
        plStack_178 = (longlong *)0x0;
        pcStack_190 = (code *)0x0;
        plStack_188 = (longlong *)0x0;
        pcStack_130 = _PyRuntime_exref;
        plVar7 = (longlong *)0x0;
        goto LAB_23e74cd15;
      }
LAB_23e74d2b0:
      plStack_138 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      plStack_140 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      pcStack_180 = (code *)0x0;
      pcStack_170 = (code *)0x0;
      plStack_178 = (longlong *)0x0;
      pcStack_190 = (code *)0x0;
      plStack_188 = (longlong *)0x0;
      pcVar14 = apcStack_88[0];
      goto LAB_23e74cdb2;
    }
    pcVar17 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    in_R10 = (longlong *)&DAT_23ed6a4f8;
    iVar5 = 0x2ed;
    plStack_140 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_150 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
    plStack_168 = (longlong *)0x0;
    pcStack_180 = (code *)0x0;
    pcStack_170 = (code *)0x0;
    plStack_178 = (longlong *)0x0;
    pcStack_190 = (code *)0x0;
    plStack_188 = (longlong *)0x0;
    pcStack_130 = _PyRuntime_exref;
    plVar7 = (longlong *)0x0;
    apcStack_88[0] = (code *)0x0;
LAB_23e74d80f:
    pcVar14 = (code *)*in_R10;
    if (pcVar14 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar18 = apcStack_88[0];
    }
    else {
      *in_R10 = *(longlong *)pcVar14;
      *(longlong *)pcVar14 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar18 = (code *)0x0;
    }
    *(longlong *)(pcVar14 + 0x10) = 0;
    *(longlong **)(pcVar14 + 0x18) = plVar1;
    *plVar1 = *plVar1 + 1;
    lVar12 = *(longlong *)(pcStack_130 + 0x1f8);
    *(int *)(pcVar14 + 0x24) = iVar5;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar15 = *(longlong *)(pcVar14 + -8);
    puVar23 = *(undefined8 **)(lVar12 + 8);
    *puVar23 = pcVar14 + -0x10;
    *(longlong *)(pcVar14 + -0x10) = lVar12;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar23;
    *(code **)(lVar12 + 8) = pcVar14 + -0x10;
    if ((pcVar18 != (code *)0x0) &&
       (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
      (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
    }
  }
  else {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar25,DAT_23eed8a98);
    if (plVar7 == (longlong *)0x0) {
LAB_23e74cc20:
      pcVar17 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      auVar24 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcVar14 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e74cc39:
      auStack_98 = auVar24;
      pcStack_90 = pcVar14;
      if (pcVar17 == (code *)0x0) {
        pcVar17 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        in_R10 = (longlong *)&DAT_23ed6a4f8;
        iVar5 = 0x2f0;
        plStack_140 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_158 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        pcStack_180 = (code *)0x0;
        pcStack_170 = (code *)0x0;
        plStack_178 = (longlong *)0x0;
        pcStack_190 = (code *)0x0;
        plStack_188 = (longlong *)0x0;
        pcStack_130 = _PyRuntime_exref;
        plVar7 = (longlong *)0x0;
        apcStack_88[0] = (code *)0x0;
        goto LAB_23e74d80f;
      }
      apcStack_88[0] = pcVar17;
      if (plVar1 == *(longlong **)(pcVar17 + 0x18)) goto LAB_23e74d2b0;
      pcVar17 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      in_R10 = (longlong *)&DAT_23ed6a4f8;
      plStack_140 = (longlong *)0x0;
      iVar5 = 0x2f0;
      plStack_148 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      pcStack_180 = (code *)0x0;
      pcStack_170 = (code *)0x0;
      plStack_178 = (longlong *)0x0;
      pcStack_190 = (code *)0x0;
      plStack_188 = (longlong *)0x0;
      pcStack_130 = _PyRuntime_exref;
    }
    else {
      *(undefined4 *)(plVar1 + 5) = 0x2f0;
      plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eed8c18);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
        if (plVar8 != (longlong *)0x0) goto LAB_23e74bed4;
        goto LAB_23e74cc20;
      }
      if (plVar8 == (longlong *)0x0) goto LAB_23e74cc20;
LAB_23e74bed4:
      plVar9 = (longlong *)FUN_23a388310();
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      if (plVar9 == (longlong *)0x0) goto LAB_23e74cc20;
      plVar7 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
      if ((plVar7 == (longlong *)0x0) &&
         (plVar7 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,2), plVar7 == (longlong *)0x0)) {
        plVar8 = (longlong *)0x0;
LAB_23e74d380:
        pcVar17 = apcStack_88[0];
        pcVar14 = pcStack_90;
        auVar24 = auStack_98;
        apcStack_88[0] = (code *)0x0;
        _auStack_98 = (undefined1  [16])0x0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        apcStack_88[0] = (code *)0x0;
        auStack_98 = (undefined1  [8])0x0;
        pcStack_90 = (code *)0x0;
        if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
          (**(code **)(plVar7[1] + 0x30))();
        }
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        goto LAB_23e74cc39;
      }
      plVar8 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
      if (((plVar8 == (longlong *)0x0) &&
          (plVar8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,2), plVar8 == (longlong *)0x0))
         || (cVar4 = FUN_23a3884a0(param_1,auStack_98,plVar9,2), cVar4 == '\0')) goto LAB_23e74d380;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      lVar12 = *(longlong *)(DAT_23eed8950 + 0x20);
      if (*(char *)(lVar12 + 10) == '\0') {
        plVar9 = (longlong *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed9140);
        if (plVar9 == (longlong *)0x0) goto LAB_23e74d4a9;
        lVar22 = *plVar9;
LAB_23e74db78:
        if (lVar22 == 0) goto LAB_23e74d4a9;
LAB_23e74bffa:
        *(undefined4 *)(plVar1 + 5) = 0x2f1;
        auStack_78._8_8_ = plVar8;
        auStack_78._0_8_ = plVar7;
        plVar9 = (longlong *)FUN_23e94ed00(param_1,lVar22,auStack_78);
        if (plVar9 == (longlong *)0x0) {
LAB_23e74d910:
          auVar24 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar14 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar17 = *(code **)(param_1 + 0x68);
          goto LAB_23e74d64b;
        }
        plVar10 = (longlong *)FUN_23a388310();
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        if (plVar10 == (longlong *)0x0) goto LAB_23e74d910;
        plVar11 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
        if ((plVar11 == (longlong *)0x0) &&
           (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,4), plVar11 == (longlong *)0x0)
           ) {
          pcStack_190 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          plStack_188 = (longlong *)0x0;
LAB_23e74d540:
          pcVar14 = apcStack_88[0];
          pcVar17 = pcStack_90;
          auVar24 = auStack_98;
          apcStack_88[0] = (code *)0x0;
          _auStack_98 = (undefined1  [16])0x0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          apcStack_88[0] = (code *)0x0;
          auStack_98 = (undefined1  [8])0x0;
          pcStack_90 = (code *)0x0;
          if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if ((plStack_188 != (longlong *)0x0) &&
             (lVar12 = *plStack_188, *plStack_188 = lVar12 + -1, lVar12 + -1 == 0)) {
            (**(code **)(plStack_188[1] + 0x30))();
          }
          if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if ((pcStack_190 != (code *)0x0) &&
             (lVar12 = *(longlong *)pcStack_190, *(longlong *)pcStack_190 = lVar12 + -1,
             lVar12 + -1 == 0)) {
            (**(code **)(*(longlong *)(pcStack_190 + 8) + 0x30))();
          }
          goto LAB_23e74d64b;
        }
        plStack_188 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
        if ((plStack_188 == (longlong *)0x0) &&
           (plStack_188 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,4),
           plStack_188 == (longlong *)0x0)) {
          pcStack_190 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          goto LAB_23e74d540;
        }
        plVar9 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
        if ((plVar9 == (longlong *)0x0) &&
           (plVar9 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2,4), plVar9 == (longlong *)0x0))
        {
          pcStack_190 = (code *)0x0;
          goto LAB_23e74d540;
        }
        pcStack_190 = (code *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
        if (((pcStack_190 == (code *)0x0) &&
            (pcStack_190 = (code *)FUN_23a3c1b70(param_1,auStack_98,3,4), pcStack_190 == (code *)0x0
            )) || (cVar4 = FUN_23a3884a0(param_1,auStack_98,plVar10,4), cVar4 == '\0'))
        goto LAB_23e74d540;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (*plStack_188 == 0) {
          (**(code **)(plStack_188[1] + 0x30))();
        }
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (*(longlong *)pcStack_190 == 0) {
          (**(code **)(*(longlong *)(pcStack_190 + 8) + 0x30))();
        }
        plStack_178 = (longlong *)FUN_23e8bc2f0(plVar25,DAT_23eed8b40);
        pcVar14 = _DAT_23eed9148;
        if (plStack_178 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (apcStack_88[0] != (code *)0x0) {
            if (plVar1 != *(longlong **)(apcStack_88[0] + 0x18)) {
              pcStack_130 = _PyRuntime_exref;
              pcVar17 = (code *)0x0;
              plStack_138 = (longlong *)0x0;
              iVar5 = 0x2f3;
              plStack_140 = (longlong *)0x0;
              in_R10 = (longlong *)&DAT_23ed6a4f8;
              plStack_148 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_168 = (longlong *)0x0;
              pcStack_180 = (code *)0x0;
              pcStack_170 = (code *)0x0;
              goto LAB_23e74cd15;
            }
            goto LAB_23e74de3b;
          }
          pcStack_130 = _PyRuntime_exref;
          apcStack_88[0] = (code *)0x0;
          goto LAB_23e74ee79;
        }
        lVar12 = *(longlong *)(param_1 + 0x10);
        pcVar17 = *(code **)(lVar12 + 0xe40);
        if (pcVar17 == (code *)0x0) {
          pcStack_180 = _DAT_23eed9148;
          pcVar17 = (code *)FUN_23e916a20(PyTuple_Type_exref,6);
        }
        else {
          lVar15 = *(longlong *)((longlong)pcVar17 + 0x18);
          *(int *)(lVar12 + 0xecc) = *(int *)(lVar12 + 0xecc) + -1;
          *(longlong *)(lVar12 + 0xe40) = lVar15;
          *(longlong *)pcVar17 = 1;
        }
        pcStack_130 = _PyRuntime_exref;
        *(longlong *)((longlong)pcVar17 + 0x40) = 0;
        *(undefined1 (*) [16])((longlong)pcVar17 + 0x20) = (undefined1  [16])0x0;
        lVar12 = *(longlong *)(pcStack_130 + 0x1f8);
        *(undefined1 (*) [16])((longlong)pcVar17 + 0x30) = (undefined1  [16])0x0;
        lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
        lVar15 = *(longlong *)((longlong)pcVar17 + -8);
        puVar23 = *(undefined8 **)(lVar12 + 8);
        *puVar23 = (longlong *)((longlong)pcVar17 + -0x10);
        *(longlong *)((longlong)pcVar17 + -0x10) = lVar12;
        *(ulonglong *)((longlong)pcVar17 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar23;
        *(longlong **)(lVar12 + 8) = (longlong *)((longlong)pcVar17 + -0x10);
        *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
        *(code **)((longlong)pcVar17 + 0x18) = pcVar14;
        uVar3 = DAT_23ed6cd28;
        plStack_b0 = plVar8;
        plStack_e0 = plVar7;
        plVar10 = plVar9;
        plStack_c0 = plVar11;
        plStack_b8 = plVar25;
        if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23e74c239:
          iVar5 = (int)pcVar14;
          auStack_78._8_8_ = uVar3;
          auStack_78._0_8_ = pcStack_190;
          lVar12 = FUN_23e94ed00();
          if (lVar12 == 0) {
LAB_23e74db90:
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            lVar12 = *plStack_178;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plStack_178 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(plStack_178[1] + 0x30))();
            }
            *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
            if (*(longlong *)pcVar17 == 0) {
              (**(code **)(*(longlong *)((longlong)pcVar17 + 8) + 0x30))();
              if (apcStack_88[0] == (code *)0x0) goto LAB_23e74ee79;
              plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
            }
            else {
              if (apcStack_88[0] == (code *)0x0) {
LAB_23e74ee79:
                plStack_138 = (longlong *)0x0;
                in_R10 = (longlong *)&DAT_23ed6a4f8;
                pcVar17 = (code *)0x0;
                plStack_140 = (longlong *)0x0;
                iVar5 = 0x2f3;
                plStack_148 = (longlong *)0x0;
                plStack_150 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plStack_168 = (longlong *)0x0;
                pcStack_180 = (code *)0x0;
                pcStack_170 = (code *)0x0;
                plStack_178 = (longlong *)0x0;
                goto LAB_23e74d80f;
              }
              plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
            }
            if (plVar1 != plVar10) {
              plStack_138 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              in_R10 = (longlong *)&DAT_23ed6a4f8;
              iVar5 = 0x2f3;
              plStack_140 = (longlong *)0x0;
              plStack_148 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_168 = (longlong *)0x0;
              pcStack_180 = (code *)0x0;
              pcStack_170 = (code *)0x0;
              plStack_178 = (longlong *)0x0;
              goto LAB_23e74cd15;
            }
          }
          else {
            *(longlong *)((longlong)pcVar17 + 0x20) = lVar12;
            plVar13 = _DAT_23eed9150;
            *_DAT_23eed9150 = *_DAT_23eed9150 + 1;
            *(longlong **)((longlong)pcVar17 + 0x28) = plVar13;
            uVar3 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar13 == (longlong *)0x0) goto LAB_23e74f0f6;
              *plVar13 = *plVar13 + 1;
              DAT_23ed6a4c0 = plVar13;
            }
            auStack_78._8_8_ = uVar3;
            auStack_78._0_8_ = plStack_188;
            lVar12 = FUN_23e94ed00();
            if (lVar12 == 0) goto LAB_23e74db90;
            *(longlong *)((longlong)pcVar17 + 0x30) = lVar12;
            plVar13 = _DAT_23eed9158;
            *_DAT_23eed9158 = *_DAT_23eed9158 + 1;
            *(longlong **)((longlong)pcVar17 + 0x38) = plVar13;
            uVar3 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar13 == (longlong *)0x0) goto LAB_23e74f0f6;
              *plVar13 = *plVar13 + 1;
              DAT_23ed6a4c0 = plVar13;
            }
            auStack_78._8_8_ = uVar3;
            auStack_78._0_8_ = plVar9;
            lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,auStack_78);
            if (lVar12 == 0) goto LAB_23e74db90;
            *(longlong *)((longlong)pcVar17 + 0x40) = lVar12;
            plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar17);
            *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
            if (*(longlong *)pcVar17 == 0) {
              (**(code **)(*(longlong *)((longlong)pcVar17 + 8) + 0x30))(pcVar17);
            }
            if (plVar10 != (longlong *)0x0) {
              *(undefined4 *)(plVar1 + 5) = 0x2f3;
              plVar13 = (longlong *)FUN_23e914090(param_1,plStack_178,plVar10);
              lVar12 = *plStack_178;
              *plStack_178 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
                (**(code **)(plStack_178[1] + 0x30))();
              }
              lVar12 = *plVar10;
              *plVar10 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
                (**(code **)(plVar10[1] + 0x30))();
              }
              if (plVar13 != (longlong *)0x0) {
                lVar12 = *plVar13;
                *plVar13 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                lVar12 = FUN_23e8e0270();
                if (lVar12 == 0) {
                  FUN_23e915740(param_1,auStack_98);
                  if (apcStack_88[0] == (code *)0x0) {
LAB_23e750a3b:
                    in_R10 = (longlong *)&DAT_23ed6a4f8;
                    plStack_138 = (longlong *)0x0;
                    pcVar17 = (code *)0x0;
                    iVar5 = 0x2f6;
                    plStack_140 = (longlong *)0x0;
                    plStack_148 = (longlong *)0x0;
                    plStack_150 = (longlong *)0x0;
                    plStack_158 = (longlong *)0x0;
                    plStack_160 = (longlong *)0x0;
                    plStack_168 = (longlong *)0x0;
                    pcStack_180 = (code *)0x0;
                    pcStack_170 = (code *)0x0;
                    plStack_178 = (longlong *)0x0;
                    goto LAB_23e74d80f;
                  }
                  if (*(longlong **)(apcStack_88[0] + 0x18) == plVar1) goto LAB_23e74de3b;
                  in_R10 = (longlong *)&DAT_23ed6a4f8;
                  pcVar17 = (code *)0x0;
                  pcStack_180 = (code *)0x0;
                  pcStack_170 = (code *)0x0;
                  iVar5 = 0x2f6;
                  plStack_138 = (longlong *)0x0;
                  plStack_140 = (longlong *)0x0;
                  plStack_148 = (longlong *)0x0;
                  plStack_150 = (longlong *)0x0;
                  plStack_158 = (longlong *)0x0;
                  plStack_160 = (longlong *)0x0;
                  plStack_168 = (longlong *)0x0;
                  plStack_178 = (longlong *)0x0;
                  goto LAB_23e74cd15;
                }
                *(undefined4 *)(plVar1 + 5) = 0x2f6;
                auStack_78._8_8_ = plVar9;
                auStack_78._0_8_ = plStack_188;
                apcStack_68[0] = pcStack_190;
                plStack_178 = (longlong *)FUN_23e956150(param_1,lVar12);
                pcStack_170 = DAT_23ed6ccf0;
                if (plStack_178 == (longlong *)0x0) {
                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_90 = *(code **)(param_1 + 0x68);
                  apcStack_88[0] = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (apcStack_88[0] == (code *)0x0) goto LAB_23e750a3b;
                  plStack_138 = (longlong *)0x0;
                  pcVar17 = (code *)0x0;
                  plStack_140 = (longlong *)0x0;
                  plStack_148 = (longlong *)0x0;
                  plStack_150 = (longlong *)0x0;
                  plStack_158 = (longlong *)0x0;
                  plStack_160 = (longlong *)0x0;
                  plStack_168 = (longlong *)0x0;
                  pcStack_180 = (code *)0x0;
                  pcStack_170 = (code *)0x0;
                  pcVar14 = apcStack_88[0];
                  if (*(longlong **)(apcStack_88[0] + 0x18) == plVar1) goto LAB_23e74cdb2;
                  in_R10 = (longlong *)&DAT_23ed6a4f8;
                  iVar5 = 0x2f6;
                  goto LAB_23e74cd15;
                }
                *(longlong *)DAT_23ed6ccf0 = *(longlong *)DAT_23ed6ccf0 + 1;
                if (plVar25 == (longlong *)0x0) {
                  FUN_23e8ba2b0(auStack_98,DAT_23eed8d30);
                  pcStack_f8 = _Py_NoneStruct_exref;
                  if ((auStack_98 != (undefined1  [8])_Py_NoneStruct_exref) &&
                     (auStack_98 != (undefined1  [8])0x0)) {
                    FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
                  }
                  pcVar17 = (code *)0x0;
                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138));
                  pcStack_180 = (code *)0x0;
                  uVar21 = 0x2fc;
                  plStack_138 = (longlong *)0x0;
                  plStack_140 = (longlong *)0x0;
                  plStack_148 = (longlong *)0x0;
                  plStack_150 = (longlong *)0x0;
                  plStack_158 = (longlong *)0x0;
                  plStack_160 = (longlong *)0x0;
                  plStack_168 = (longlong *)0x0;
                }
                else {
                  plStack_138 = (longlong *)0x0;
                  plStack_140 = (longlong *)0x0;
                  plStack_148 = (longlong *)0x0;
                  plStack_150 = (longlong *)0x0;
                  plStack_158 = (longlong *)0x0;
                  plStack_160 = (longlong *)0x0;
                  plStack_168 = (longlong *)0x0;
                  pcStack_f0 = (code *)0x0;
                  pcStack_180 = (code *)0x0;
LAB_23e74c518:
                  pcVar17 = pcStack_f0;
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar25,DAT_23eed8a08);
                  if (plVar10 != (longlong *)0x0) {
                    *(undefined4 *)(plVar1 + 5) = 0x2fc;
                    plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8d38);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e74e087;
                    iVar5 = FUN_23a35f020(plVar13);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    if (iVar5 == -1) goto LAB_23e74e087;
                    pcVar14 = _Py_FalseStruct_exref;
                    if (iVar5 == 0) {
                      pcVar14 = _Py_TrueStruct_exref;
                    }
                    iVar5 = FUN_23a35f020(pcVar14);
                    lVar12 = DAT_23eed8ff0;
                    if (iVar5 == 1) {
                      *(undefined4 *)(plVar1 + 5) = 0x2fc;
                      pcVar14 = (code *)FUN_23e915840(param_1,plVar25,DAT_23eed9100,
                                                      *(undefined8 *)(lVar12 + 0x18));
                      if (pcVar14 == (code *)0x0) goto LAB_23e74e087;
                    }
                    else {
                      *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                    }
                    iVar5 = FUN_23a35f020(pcVar14);
                    *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
                    if (*(longlong *)pcVar14 == 0) {
                      (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
                    }
                    if (iVar5 == -1) goto LAB_23e74e087;
                    plStack_118 = plVar25;
                    if (iVar5 == 0) goto LAB_23e74e677;
                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar25,DAT_23eed8a98);
                    if (plVar10 == (longlong *)0x0) {
LAB_23e74ff12:
                      apcStack_88[0] = *(code **)(param_1 + 0x70);
                      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_90 = *(code **)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar21 = 0x2fd;
                      pcStack_f8 = _Py_NoneStruct_exref;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e74e0ff;
                    }
                    *(undefined4 *)(plVar1 + 5) = 0x2fd;
                    pcVar14 = (code *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8a98);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (pcVar14 == (code *)0x0) goto LAB_23e74ff12;
                    if ((pcStack_180 != (code *)0x0) &&
                       (*(longlong *)pcStack_180 = *(longlong *)pcStack_180 + -1,
                       *(longlong *)pcStack_180 == 0)) {
                      (**(code **)(*(longlong *)(pcStack_180 + 8) + 0x30))(pcStack_180);
                    }
                    pcStack_f8 = _Py_NoneStruct_exref;
                    pcStack_180 = pcVar14;
                    if (pcVar14 != _Py_NoneStruct_exref) {
                      *(undefined4 *)(plVar1 + 5) = 0x303;
                      plVar10 = (longlong *)FUN_23e915840(param_1,plStack_178,DAT_23eed9108,pcVar14)
                      ;
                      if (plVar10 == (longlong *)0x0) {
LAB_23e75036b:
                        pcStack_f0 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        auVar24 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcVar14 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        plVar13 = (longlong *)FUN_23a388310(plVar10);
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                        }
                        if (plVar13 == (longlong *)0x0) goto LAB_23e75036b;
                        plStack_c0 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                        if ((plStack_c0 == (longlong *)0x0) &&
                           (plStack_c0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,8),
                           plStack_c0 == (longlong *)0x0)) {
                          plStack_108 = (longlong *)0x0;
                          plStack_100 = (longlong *)0x0;
                          plStack_110 = (longlong *)0x0;
                          plStack_e0 = (longlong *)0x0;
                          plStack_118 = (longlong *)0x0;
                          plStack_b0 = (longlong *)0x0;
                          plStack_b8 = (longlong *)0x0;
                          lVar12 = *plVar13;
                        }
                        else {
                          plStack_b8 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                          if ((plStack_b8 == (longlong *)0x0) &&
                             (plStack_b8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,8),
                             plStack_b8 == (longlong *)0x0)) {
                            plStack_108 = (longlong *)0x0;
                            plStack_100 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            lVar12 = *plVar13;
                          }
                          else {
                            plStack_b0 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                            if ((plStack_b0 == (longlong *)0x0) &&
                               (plStack_b0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2,8),
                               plStack_b0 == (longlong *)0x0)) {
                              plStack_108 = (longlong *)0x0;
                              plStack_100 = (longlong *)0x0;
                              plStack_110 = (longlong *)0x0;
                              plStack_e0 = (longlong *)0x0;
                              lVar12 = *plVar13;
                              plStack_118 = (longlong *)0x0;
                            }
                            else {
                              plVar10 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                              if ((plVar10 == (longlong *)0x0) &&
                                 (plVar10 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,3),
                                 plVar10 == (longlong *)0x0)) {
                                plStack_108 = (longlong *)0x0;
                                plStack_100 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                lVar12 = *plVar13;
                                plStack_e0 = (longlong *)0x0;
                                plStack_118 = plVar10;
                              }
                              else {
                                plStack_e0 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                                plStack_118 = plVar10;
                                if ((plStack_e0 == (longlong *)0x0) &&
                                   (plStack_e0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,4,8),
                                   plStack_e0 == (longlong *)0x0)) {
                                  plStack_108 = (longlong *)0x0;
                                  plStack_100 = (longlong *)0x0;
                                  lVar12 = *plVar13;
                                  plStack_110 = (longlong *)0x0;
                                }
                                else {
                                  plStack_110 = (longlong *)
                                                (**(code **)(plVar13[1] + 0xe0))(plVar13);
                                  if ((plStack_110 == (longlong *)0x0) &&
                                     (plStack_110 = (longlong *)
                                                    FUN_23a3c1b70(param_1,auStack_98,5,8),
                                     plStack_110 == (longlong *)0x0)) {
                                    lVar12 = *plVar13;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_100 = (longlong *)0x0;
                                  }
                                  else {
                                    plStack_100 = (longlong *)
                                                  (**(code **)(plVar13[1] + 0xe0))(plVar13);
                                    if ((plStack_100 == (longlong *)0x0) &&
                                       (plStack_100 = (longlong *)
                                                      FUN_23a3c1b70(param_1,auStack_98,6,8),
                                       plStack_100 == (longlong *)0x0)) {
                                      plStack_108 = (longlong *)0x0;
                                      lVar12 = *plVar13;
                                    }
                                    else {
                                      plStack_108 = (longlong *)
                                                    (**(code **)(plVar13[1] + 0xe0))(plVar13);
                                      if ((plStack_108 == (longlong *)0x0) &&
                                         (plStack_108 = (longlong *)
                                                        FUN_23a3c1b70(param_1,auStack_98,7,8),
                                         plStack_108 == (longlong *)0x0)) {
                                        lVar12 = *plVar13;
                                      }
                                      else {
                                        cVar4 = FUN_23a3884a0(param_1,auStack_98,plVar13,8);
                                        lVar12 = *plVar13;
                                        if (cVar4 != '\0') {
                                          *plVar13 = lVar12 + -1;
                                          if (lVar12 + -1 == 0) {
                                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                                          }
                                          lVar12 = *plStack_c0;
                                          *plStack_c0 = lVar12 + 1;
                                          if (pcStack_f0 != (code *)0x0) {
                                            lVar12 = *(longlong *)pcStack_f0;
                                            *(longlong *)pcStack_f0 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              (**(code **)(*(longlong *)((longlong)pcStack_f0 + 8) +
                                                          0x30))(pcStack_f0);
                                            }
                                            lVar12 = *plStack_c0 + -1;
                                          }
                                          *plStack_c0 = lVar12;
                                          if (lVar12 == 0) {
                                            (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                                          }
                                          lVar12 = *plStack_b8;
                                          *plStack_b8 = lVar12 + 1;
                                          if (plStack_168 != (longlong *)0x0) {
                                            lVar12 = *plStack_168;
                                            *plStack_168 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              (**(code **)(plStack_168[1] + 0x30))(plStack_168);
                                            }
                                            lVar12 = *plStack_b8 + -1;
                                          }
                                          *plStack_b8 = lVar12;
                                          if (lVar12 == 0) {
                                            (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                                          }
                                          lVar12 = *plStack_b0;
                                          *plStack_b0 = lVar12 + 1;
                                          if (plStack_160 != (longlong *)0x0) {
                                            lVar12 = *plStack_160;
                                            *plStack_160 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              (**(code **)(plStack_160[1] + 0x30))(plStack_160);
                                            }
                                            lVar12 = *plStack_b0 + -1;
                                          }
                                          *plStack_b0 = lVar12;
                                          if (lVar12 == 0) {
                                            (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
                                          }
                                          lVar12 = *plVar10;
                                          *plVar10 = lVar12 + 1;
                                          if (plStack_158 != (longlong *)0x0) {
                                            lVar12 = *plStack_158;
                                            *plStack_158 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              (**(code **)(plStack_158[1] + 0x30))(plStack_158);
                                            }
                                            lVar12 = *plVar10 + -1;
                                          }
                                          *plVar10 = lVar12;
                                          if (lVar12 == 0) {
                                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                                          }
                                          lVar12 = *plStack_e0;
                                          *plStack_e0 = lVar12 + 1;
                                          if (plStack_150 != (longlong *)0x0) {
                                            lVar12 = *plStack_150;
                                            *plStack_150 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              (**(code **)(plStack_150[1] + 0x30))(plStack_150);
                                            }
                                            lVar12 = *plStack_e0 + -1;
                                          }
                                          *plStack_e0 = lVar12;
                                          if (lVar12 == 0) {
                                            (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
                                          }
                                          lVar12 = *plStack_110;
                                          *plStack_110 = lVar12 + 1;
                                          if (plStack_148 != (longlong *)0x0) {
                                            lVar12 = *plStack_148;
                                            *plStack_148 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              (**(code **)(plStack_148[1] + 0x30))(plStack_148);
                                              lVar12 = *plStack_110 + -1;
                                            }
                                            else {
                                              lVar12 = *plStack_110 + -1;
                                            }
                                          }
                                          *plStack_110 = lVar12;
                                          if (lVar12 == 0) {
                                            (**(code **)(plStack_110[1] + 0x30))();
                                          }
                                          lVar12 = *plStack_100;
                                          *plStack_100 = lVar12 + 1;
                                          if (plStack_140 != (longlong *)0x0) {
                                            lVar12 = *plStack_140;
                                            *plStack_140 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              (**(code **)(plStack_140[1] + 0x30))(plStack_140);
                                              lVar12 = *plStack_100 + -1;
                                            }
                                            else {
                                              lVar12 = *plStack_100 + -1;
                                            }
                                          }
                                          *plStack_100 = lVar12;
                                          if (lVar12 == 0) {
                                            (**(code **)(plStack_100[1] + 0x30))();
                                          }
                                          lVar12 = *plStack_108;
                                          *plStack_108 = lVar12 + 1;
                                          if (plStack_138 != (longlong *)0x0) {
                                            lVar12 = *plStack_138;
                                            *plStack_138 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              (**(code **)(plStack_138[1] + 0x30))(plStack_138);
                                              lVar12 = *plStack_108 + -1;
                                            }
                                            else {
                                              lVar12 = *plStack_108 + -1;
                                            }
                                          }
                                          *plStack_108 = lVar12;
                                          if (lVar12 == 0) {
                                            (**(code **)(plStack_108[1] + 0x30))();
                                          }
                                          iVar5 = FUN_23a35f020(plStack_e0);
                                          if (iVar5 == -1) {
                                            apcStack_88[0] = *(code **)(param_1 + 0x70);
                                            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            uVar21 = 0x305;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            plStack_138 = plStack_108;
                                            plStack_140 = plStack_100;
                                            plStack_148 = plStack_110;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            pcVar17 = (code *)plStack_c0;
                                            plStack_168 = plStack_b8;
                                            plStack_160 = plStack_b0;
                                            plStack_158 = plVar10;
                                            plStack_150 = plStack_e0;
                                            pcStack_90 = *(code **)(param_1 + 0x68);
                                            goto LAB_23e74e0ff;
                                          }
                                          if (iVar5 != 0) {
                                            pcVar17 = (code *)FUN_23e8bc2f0(plVar25,DAT_23eed8b40);
                                            plVar13 = _DAT_23eed9168;
                                            if (pcVar17 == (code *)0x0) {
LAB_23e750ac0:
                                              apcStack_88[0] = *(code **)(param_1 + 0x70);
                                              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              pcStack_90 = *(code **)(param_1 + 0x68);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                            }
                                            else {
                                              lVar12 = *(longlong *)(param_1 + 0x10);
                                              plStack_168 = *(longlong **)(lVar12 + 0xe28);
                                              if (plStack_168 == (longlong *)0x0) {
                                                plStack_168 = (longlong *)
                                                              FUN_23e916a20(PyTuple_Type_exref,3);
                                              }
                                              else {
                                                lVar15 = plStack_168[3];
                                                *(int *)(lVar12 + 0xec0) =
                                                     *(int *)(lVar12 + 0xec0) + -1;
                                                *(longlong *)(lVar12 + 0xe28) = lVar15;
                                                *plStack_168 = 1;
                                              }
                                              *(undefined1 (*) [16])(plStack_168 + 4) =
                                                   (undefined1  [16])0x0;
                                              lVar12 = *(longlong *)
                                                        (*(longlong *)
                                                          (*(longlong *)(pcStack_130 + 0x1f8) + 0x10
                                                          ) + 0x2e8);
                                              lVar15 = plStack_168[-1];
                                              in_R10 = *(longlong **)(lVar12 + 8);
                                              *in_R10 = (longlong)(plStack_168 + -2);
                                              plStack_168[-2] = lVar12;
                                              plStack_168[-1] =
                                                   (ulonglong)((uint)lVar15 & 3) | (ulonglong)in_R10
                                              ;
                                              *(longlong **)(lVar12 + 8) = plStack_168 + -2;
                                              *plVar13 = *plVar13 + 1;
                                              plStack_168[3] = (longlong)plVar13;
                                              uVar3 = DAT_23ed6cd28;
                                              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                plVar13 = plStack_168;
                                                plVar16 = (longlong *)
                                                          PyDict_GetItemString
                                                                    (DAT_23ed6ccc0,"format");
                                                iVar5 = (int)plVar13;
                                                plStack_118 = plVar25;
                                                if (plVar16 == (longlong *)0x0) goto LAB_23e74f0f6;
                                                *plVar16 = *plVar16 + 1;
                                                DAT_23ed6a4c0 = plVar16;
                                              }
                                              auStack_78._8_8_ = uVar3;
                                              auStack_78._0_8_ = plStack_110;
                                              lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,
                                                                     auStack_78);
                                              if (lVar12 == 0) {
                                                auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                                                pcStack_90 = *(code **)(param_1 + 0x68);
                                                apcStack_88[0] = *(code **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
                                                if (*(longlong *)pcVar17 == 0) {
                                                  FUN_23a334bc0(pcVar17);
                                                }
                                                *plStack_168 = *plStack_168 + -1;
                                                if (*plStack_168 == 0) {
                                                  FUN_23a334bc0(plStack_168);
                                                }
                                              }
                                              else {
                                                plStack_168[4] = lVar12;
                                                plVar13 = _DAT_23eed9170;
                                                *_DAT_23eed9170 = *_DAT_23eed9170 + 1;
                                                plStack_168[5] = (longlong)plVar13;
                                                plVar13 = (longlong *)
                                                          PyUnicode_Join(DAT_23ed6cd28,plStack_168);
                                                *plStack_168 = *plStack_168 + -1;
                                                if (*plStack_168 == 0) {
                                                  (**(code **)(plStack_168[1] + 0x30))(plStack_168);
                                                }
                                                if (plVar13 != (longlong *)0x0) {
                                                  *(undefined4 *)(plVar1 + 5) = 0x306;
                                                  plVar16 = (longlong *)
                                                            FUN_23e914090(param_1,pcVar17);
                                                  *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
                                                  if (*(longlong *)pcVar17 == 0) {
                                                    (**(code **)(*(longlong *)
                                                                  ((longlong)pcVar17 + 8) + 0x30))
                                                              (pcVar17);
                                                  }
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                                  }
                                                  if (plVar16 != (longlong *)0x0) {
                                                    *plVar16 = *plVar16 + -1;
                                                    if (*plVar16 == 0) {
                                                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                                                    }
                                                    goto LAB_23e74caaf;
                                                  }
                                                  goto LAB_23e750ac0;
                                                }
                                                auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                                                pcStack_90 = *(code **)(param_1 + 0x68);
                                                apcStack_88[0] = *(code **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
                                                if (*(longlong *)pcVar17 == 0) {
                                                  FUN_23a334bc0(pcVar17);
                                                }
                                              }
                                            }
                                            uVar21 = 0x306;
                                            plStack_138 = plStack_108;
                                            plStack_140 = plStack_100;
                                            plStack_148 = plStack_110;
                                            pcVar17 = (code *)plStack_c0;
                                            plStack_168 = plStack_b8;
                                            plStack_160 = plStack_b0;
                                            plStack_158 = plVar10;
                                            plStack_150 = plStack_e0;
                                            goto LAB_23e74e0ff;
                                          }
LAB_23e74caaf:
                                          lVar12 = FUN_23e8e0ba0();
                                          if (lVar12 == 0) {
                                            FUN_23e915740(param_1,auStack_98,DAT_23eed8c70);
                                          }
                                          else {
                                            *(undefined4 *)(plVar1 + 5) = 0x30a;
                                            plVar13 = (longlong *)
                                                      FUN_23e915840(param_1,lVar12,DAT_23eed8d40);
                                            if (plVar13 != (longlong *)0x0) {
                                              *plVar13 = *plVar13 + -1;
                                              if (*plVar13 == 0) {
                                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                                              }
                                              if (pcStack_170 == (code *)0x0) {
                                                FUN_23e8ba2b0(auStack_98,DAT_23eed9110);
                                                if ((auStack_98 !=
                                                     (undefined1  [8])_Py_NoneStruct_exref) &&
                                                   (auStack_98 != (undefined1  [8])0x0)) {
                                                  FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,
                                                                apcStack_88);
                                                }
                                                FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),
                                                              pcStack_90);
                                                uVar21 = 0x30b;
                                                plStack_138 = plStack_108;
                                                plStack_140 = plStack_100;
                                                plStack_148 = plStack_110;
                                                pcVar17 = (code *)plStack_c0;
                                                plStack_168 = plStack_b8;
                                                plStack_160 = plStack_b0;
                                                plStack_158 = plVar10;
                                                plStack_150 = plStack_e0;
                                                goto LAB_23e74e0ff;
                                              }
                                              auStack_78._0_8_ = pcStack_170;
                                              FUN_23e8d34a0(auStack_78);
                                              lVar12 = *(longlong *)(param_1 + 0x10);
                                              pcStack_170 = (code *)auStack_78._0_8_;
                                              if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160)
                                                     == 0) && (*(int *)(lVar12 + 0x78) == 0)) ||
                                                  (iVar5 = Py_MakePendingCalls(), -1 < iVar5)) ||
                                                 (*(longlong *)(param_1 + 0x60) == 0)) {
                                                if (*(int *)(lVar12 + 0x68) != 0) {
                                                  PyEval_SaveThread();
                                                  PyEval_AcquireThread(param_1);
                                                }
                                                plVar13 = *(longlong **)(param_1 + 0x90);
                                                if (plVar13 == (longlong *)0x0) {
                                                  plStack_138 = plStack_108;
                                                  plStack_140 = plStack_100;
                                                  plStack_148 = plStack_110;
                                                  plStack_168 = plStack_b8;
                                                  plStack_160 = plStack_b0;
                                                  plStack_158 = plVar10;
                                                  plStack_150 = plStack_e0;
                                                  pcStack_f0 = (code *)plStack_c0;
                                                  goto LAB_23e74c518;
                                                }
                                                plVar16 = *(longlong **)(param_1 + 0x60);
                                                plVar19 = *(longlong **)(param_1 + 0x68);
                                                plVar2 = *(longlong **)(param_1 + 0x70);
                                                *(longlong **)(param_1 + 0x60) = plVar13;
                                                *(undefined8 *)(param_1 + 0x90) = 0;
                                                *plVar13 = *plVar13 + 1;
                                                *(undefined8 *)(param_1 + 0x68) = 0;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                if ((plVar16 != (longlong *)0x0) &&
                                                   (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                                  (**(code **)(plVar16[1] + 0x30))();
                                                }
                                                if ((plVar19 != (longlong *)0x0) &&
                                                   (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                                                  (**(code **)(plVar19[1] + 0x30))(plVar19);
                                                }
                                                if ((plVar2 != (longlong *)0x0) &&
                                                   (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
                                                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                                                }
                                              }
                                              apcStack_88[0] = *(code **)(param_1 + 0x70);
                                              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              uVar21 = 0x2fc;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plStack_138 = plStack_108;
                                              plStack_140 = plStack_100;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_148 = plStack_110;
                                              pcVar17 = (code *)plStack_c0;
                                              plStack_168 = plStack_b8;
                                              plStack_160 = plStack_b0;
                                              plStack_158 = plVar10;
                                              plStack_150 = plStack_e0;
                                              pcStack_90 = *(code **)(param_1 + 0x68);
                                              goto LAB_23e74e0ff;
                                            }
                                            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            pcStack_90 = *(code **)(param_1 + 0x68);
                                            apcStack_88[0] = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          uVar21 = 0x30a;
                                          plStack_138 = plStack_108;
                                          plStack_140 = plStack_100;
                                          plStack_148 = plStack_110;
                                          pcVar17 = (code *)plStack_c0;
                                          plStack_168 = plStack_b8;
                                          plStack_160 = plStack_b0;
                                          plStack_158 = plVar10;
                                          plStack_150 = plStack_e0;
                                          goto LAB_23e74e0ff;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        pcStack_f0 = apcStack_88[0];
                        pcVar14 = pcStack_90;
                        auVar24 = auStack_98;
                        apcStack_88[0] = (code *)0x0;
                        _auStack_98 = (undefined1  [16])0x0;
                        *plVar13 = lVar12 + -1;
                        if (lVar12 + -1 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        apcStack_88[0] = (code *)0x0;
                        auStack_98 = (undefined1  [8])0x0;
                        pcStack_90 = (code *)0x0;
                        if ((plStack_c0 != (longlong *)0x0) &&
                           (lVar12 = *plStack_c0, *plStack_c0 = lVar12 + -1, lVar12 + -1 == 0)) {
                          (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                        }
                        if ((plStack_b8 != (longlong *)0x0) &&
                           (lVar12 = *plStack_b8, *plStack_b8 = lVar12 + -1, lVar12 + -1 == 0)) {
                          (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                        }
                        if ((plStack_b0 != (longlong *)0x0) &&
                           (lVar12 = *plStack_b0, *plStack_b0 = lVar12 + -1, lVar12 + -1 == 0)) {
                          (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
                        }
                        if ((plStack_118 != (longlong *)0x0) &&
                           (lVar12 = *plStack_118, *plStack_118 = lVar12 + -1, lVar12 + -1 == 0)) {
                          (**(code **)(plStack_118[1] + 0x30))(plStack_118);
                        }
                        if ((plStack_e0 != (longlong *)0x0) &&
                           (lVar12 = *plStack_e0, *plStack_e0 = lVar12 + -1, lVar12 + -1 == 0)) {
                          (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
                        }
                        if ((plStack_110 != (longlong *)0x0) &&
                           (lVar12 = *plStack_110, *plStack_110 = lVar12 + -1, lVar12 + -1 == 0)) {
                          (**(code **)(plStack_110[1] + 0x30))(plStack_110);
                        }
                        if ((plStack_100 != (longlong *)0x0) &&
                           (lVar12 = *plStack_100, *plStack_100 = lVar12 + -1, lVar12 + -1 == 0)) {
                          (**(code **)(plStack_100[1] + 0x30))(plStack_100);
                        }
                        if ((plStack_108 != (longlong *)0x0) &&
                           (lVar12 = *plStack_108, *plStack_108 = lVar12 + -1, lVar12 + -1 == 0)) {
                          (**(code **)(plStack_108[1] + 0x30))(plStack_108);
                        }
                      }
                      uVar21 = 0x303;
                      apcStack_88[0] = pcStack_f0;
                      auStack_98 = auVar24;
                      pcStack_90 = pcVar14;
                      goto LAB_23e74e0ff;
                    }
                    lVar15 = FUN_23e8e0ba0();
                    lVar12 = DAT_23eed8e78;
                    if (lVar15 == 0) {
                      FUN_23e915740(param_1,auStack_98,DAT_23eed8c70);
LAB_23e750408:
                      pcStack_180 = _Py_NoneStruct_exref;
                      uVar21 = 0x2ff;
                      goto LAB_23e74e0ff;
                    }
                    *(undefined4 *)(plVar1 + 5) = 0x2ff;
                    plVar10 = (longlong *)
                              FUN_23e915840(param_1,lVar15,DAT_23eed8d40,
                                            *(undefined8 *)(lVar12 + 0x18));
                    if (plVar10 == (longlong *)0x0) {
                      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_90 = *(code **)(param_1 + 0x68);
                      apcStack_88[0] = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e750408;
                    }
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    goto LAB_23e74c518;
                  }
LAB_23e74e087:
                  apcStack_88[0] = *(code **)(param_1 + 0x70);
                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_90 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar21 = 0x2fc;
                  pcStack_f8 = _Py_NoneStruct_exref;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
LAB_23e74e0ff:
                pcVar14 = apcStack_88[0];
                auStack_78._8_8_ = pcStack_90;
                auStack_78._0_8_ = auStack_98;
                apcStack_88[0] = (code *)0x0;
                auStack_98 = (undefined1  [8])0x0;
                pcStack_90 = (code *)0x0;
                apcStack_68[0] = pcVar14;
                plStack_118 = *(longlong **)(param_1 + 0x138);
                if (plStack_118 != (longlong *)0x0) {
                  *plStack_118 = *plStack_118 + 1;
                }
                pcVar18 = DAT_23ed6a4f8;
                if (pcVar14 == (code *)0x0) {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar14 = *(code **)DAT_23ed6a4f8;
                    *(longlong *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar14;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  *(longlong *)(pcVar18 + 0x10) = 0;
                  *(longlong **)(pcVar18 + 0x18) = plVar1;
                  *plVar1 = *plVar1 + 1;
                  *(undefined4 *)(pcVar18 + 0x24) = uVar21;
                  *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
                  lVar12 = *(longlong *)
                            (*(longlong *)(*(longlong *)(pcStack_130 + 0x1f8) + 0x10) + 0x2e8);
                  lVar15 = *(longlong *)(pcVar18 + -8);
                  puVar23 = *(undefined8 **)(lVar12 + 8);
                  *puVar23 = pcVar18 + -0x10;
                  *(longlong *)(pcVar18 + -0x10) = lVar12;
                  *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar23;
                  *(code **)(lVar12 + 8) = pcVar18 + -0x10;
                  if ((apcStack_68[0] != (code *)0x0) &&
                     (*(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + -1,
                     *(longlong *)apcStack_68[0] == 0)) {
                    (**(code **)(*(longlong *)(apcStack_68[0] + 8) + 0x30))(apcStack_68[0]);
                  }
                }
                else {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar20 = *(code **)DAT_23ed6a4f8;
                    *(longlong *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar20;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  *(longlong **)(pcVar18 + 0x18) = plVar1;
                  *plVar1 = *plVar1 + 1;
                  *(undefined4 *)(pcVar18 + 0x24) = uVar21;
                  *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
                  lVar12 = *(longlong *)
                            (*(longlong *)(*(longlong *)(pcStack_130 + 0x1f8) + 0x10) + 0x2e8);
                  puVar23 = *(undefined8 **)(lVar12 + 8);
                  *puVar23 = pcVar18 + -0x10;
                  *(longlong *)(pcVar18 + -0x10) = lVar12;
                  *(ulonglong *)(pcVar18 + -8) =
                       (ulonglong)puVar23 | (ulonglong)((uint)*(longlong *)(pcVar18 + -8) & 3);
                  *(code **)(lVar12 + 8) = pcVar18 + -0x10;
                  *(code **)(pcVar18 + 0x10) = pcVar14;
                  *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                  if ((apcStack_68[0] != (code *)0x0) &&
                     (*(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + -1,
                     *(longlong *)apcStack_68[0] == 0)) {
                    (**(code **)(*(longlong *)(apcStack_68[0] + 8) + 0x30))(apcStack_68[0]);
                  }
                }
                in_R10 = (longlong *)&DAT_23ed6a4f8;
                apcStack_68[0] = pcVar18;
                if (((code *)auStack_78._0_8_ != pcStack_f8) &&
                   ((code *)auStack_78._0_8_ != (code *)0x0)) {
                  FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,apcStack_68);
                }
                plVar10 = *(longlong **)(auStack_78._8_8_ + 0x28);
                if (apcStack_68[0] == pcStack_f8) {
                  pcVar14 = (code *)0x0;
                }
                else {
                  pcVar14 = apcStack_68[0];
                  if (apcStack_68[0] != (code *)0x0) {
                    *(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + 1;
                  }
                }
                *(code **)(auStack_78._8_8_ + 0x28) = pcVar14;
                if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                  (**(code **)(plVar10[1] + 0x30))();
                }
                plVar10 = *(longlong **)(param_1 + 0x138);
                *(undefined8 *)(param_1 + 0x138) = auStack_78._8_8_;
                if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                  (**(code **)(plVar10[1] + 0x30))();
                }
                *(longlong *)auStack_78._0_8_ = *(longlong *)auStack_78._0_8_ + -1;
                if (*(longlong *)auStack_78._0_8_ == 0) {
                  (**(code **)(*(longlong *)(auStack_78._0_8_ + 8) + 0x30))();
                }
                if ((apcStack_68[0] != (code *)0x0) &&
                   (*(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + -1,
                   *(longlong *)apcStack_68[0] == 0)) {
                  (**(code **)(*(longlong *)(apcStack_68[0] + 8) + 0x30))();
                }
                apcStack_68[0] = (code *)0x0;
                auStack_78 = (undefined1  [16])0x0;
                iVar6 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8));
                pcVar18 = *(code **)(param_1 + 0x138);
                iVar5 = 0;
                plStack_b0 = plVar8;
                plStack_e0 = plVar7;
                plVar10 = plVar9;
                plStack_c0 = plVar11;
                plStack_b8 = plVar25;
                if (iVar6 == 0) goto LAB_23e74f109;
                *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                if (plVar25 == (longlong *)0x0) {
                  pcStack_90 = (code *)PyUnicode_FromFormat
                                                 ("cannot access local variable \'%U\' where it is not associated with a value"
                                                  ,DAT_23eed8d30);
                  auStack_98 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
                  *(longlong *)auStack_98 = *(longlong *)auStack_98 + 1;
                  apcStack_88[0] = (code *)0x0;
                  if (auStack_98 != (undefined1  [8])pcStack_f8) {
                    FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
                  }
                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_90);
                  pcVar20 = pcStack_90;
                  pcVar14 = apcStack_88[0];
                  auVar24 = auStack_98;
                }
                else {
                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar25,DAT_23eed8b40);
                  plVar10 = _DAT_23eed9180;
                  if (plVar13 == (longlong *)0x0) {
                    auVar24 = *(undefined1 (*) [8])(param_1 + 0x60);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcVar14 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcVar20 = *(code **)(param_1 + 0x68);
                  }
                  else {
                    lVar12 = *(longlong *)(param_1 + 0x10);
                    plVar16 = *(longlong **)(lVar12 + 0xe20);
                    if (plVar16 == (longlong *)0x0) {
                      plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                    }
                    else {
                      lVar15 = plVar16[3];
                      *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                      *(longlong *)(lVar12 + 0xe20) = lVar15;
                      *plVar16 = 1;
                    }
                    plVar16[4] = 0;
                    lVar12 = *(longlong *)
                              (*(longlong *)(*(longlong *)(pcStack_130 + 0x1f8) + 0x10) + 0x2e8);
                    lVar15 = plVar16[-1];
                    puVar23 = *(undefined8 **)(lVar12 + 8);
                    *puVar23 = plVar16 + -2;
                    plVar16[-2] = lVar12;
                    plVar16[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar23;
                    *(longlong **)(lVar12 + 8) = plVar16 + -2;
                    *plVar10 = *plVar10 + 1;
                    plVar16[3] = (longlong)plVar10;
                    uVar3 = DAT_23ed6cd28;
                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                      plVar10 = plVar16;
                      plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      iVar5 = (int)plVar10;
                      plVar10 = plVar9;
                      if (plVar19 == (longlong *)0x0) goto LAB_23e74f0f6;
                      *plVar19 = *plVar19 + 1;
                      DAT_23ed6a4c0 = plVar19;
                    }
                    uStack_a0 = uVar3;
                    pcStack_a8 = pcVar18;
                    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_a8);
                    if (lVar12 == 0) {
                      apcStack_88[0] = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_90 = *(code **)(param_1 + 0x68);
                      lVar12 = *plVar13;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      *plVar16 = *plVar16 + -1;
                      pcVar20 = pcStack_90;
                      pcVar14 = apcStack_88[0];
                      auVar24 = auStack_98;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                        pcVar20 = pcStack_90;
                        pcVar14 = apcStack_88[0];
                        auVar24 = auStack_98;
                      }
                    }
                    else {
                      plVar16[4] = lVar12;
                      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      if (plVar10 == (longlong *)0x0) {
                        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_90 = *(code **)(param_1 + 0x68);
                        apcStack_88[0] = *(code **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        lVar12 = *plVar13;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *plVar13 = lVar12 + -1;
                        pcVar20 = pcStack_90;
                        pcVar14 = apcStack_88[0];
                        auVar24 = auStack_98;
                        if (lVar12 + -1 == 0) {
                          FUN_23a334bc0(plVar13);
                          pcVar20 = pcStack_90;
                          pcVar14 = apcStack_88[0];
                          auVar24 = auStack_98;
                        }
                      }
                      else {
                        *(undefined4 *)(plVar1 + 5) = 0x30e;
                        plVar16 = (longlong *)FUN_23e914090(param_1,plVar13);
                        lVar12 = *plVar13;
                        *plVar13 = lVar12 + -1;
                        if (lVar12 + -1 == 0) {
                          (**(code **)(plVar13[1] + 0x30))();
                        }
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))();
                        }
                        if (plVar16 != (longlong *)0x0) {
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                          }
                          lVar12 = *(longlong *)pcVar18;
                          *(longlong *)pcVar18 = lVar12 + -1;
                          if (lVar12 + -1 == 0) {
                            (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
                          }
                          plVar10 = *(longlong **)(param_1 + 0x138);
                          *(longlong **)(param_1 + 0x138) = plStack_118;
                          if ((plVar10 != (longlong *)0x0) &&
                             (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                            (**(code **)(plVar10[1] + 0x30))();
                          }
LAB_23e74e677:
                          plVar13 = (longlong *)FUN_23e8bc2f0(plVar25,DAT_23eed8b40);
                          plVar10 = _DAT_23eed9188;
                          if (plVar13 == (longlong *)0x0) {
LAB_23e750088:
                            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pcStack_90 = *(code **)(param_1 + 0x68);
                            apcStack_88[0] = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e750157:
                            if (apcStack_88[0] == (code *)0x0) {
LAB_23e75015d:
                              in_R10 = (longlong *)&DAT_23ed6a4f8;
                              iVar5 = 0x310;
                              goto LAB_23e74d80f;
                            }
LAB_23e7500ba:
                            plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
                          }
                          else {
                            lVar12 = *(longlong *)(param_1 + 0x10);
                            plVar16 = *(longlong **)(lVar12 + 0xe28);
                            if (plVar16 == (longlong *)0x0) {
                              plStack_118 = _DAT_23eed9188;
                              plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                            }
                            else {
                              lVar15 = plVar16[3];
                              *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
                              *(longlong *)(lVar12 + 0xe28) = lVar15;
                              *plVar16 = 1;
                            }
                            *(undefined1 (*) [16])(plVar16 + 4) = (undefined1  [16])0x0;
                            lVar12 = *(longlong *)
                                      (*(longlong *)(*(longlong *)(pcStack_130 + 0x1f8) + 0x10) +
                                      0x2e8);
                            lVar15 = plVar16[-1];
                            puVar23 = *(undefined8 **)(lVar12 + 8);
                            *puVar23 = plVar16 + -2;
                            plVar16[-2] = lVar12;
                            plVar16[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar23;
                            *(longlong **)(lVar12 + 8) = plVar16 + -2;
                            *plVar10 = *plVar10 + 1;
                            plVar16[3] = (longlong)plVar10;
                            uVar3 = DAT_23ed6cd28;
                            if (pcStack_170 == (code *)0x0) {
                              FUN_23e8ba2b0(auStack_98,DAT_23eed9110);
                              if ((auStack_98 != (undefined1  [8])_Py_NoneStruct_exref) &&
                                 (auStack_98 != (undefined1  [8])0x0)) {
                                FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
                              }
                              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_90);
LAB_23e75011c:
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                FUN_23a334bc0();
                              }
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                FUN_23a334bc0();
                                goto joined_r0x00023e750157;
                              }
                              if (apcStack_88[0] != (code *)0x0) goto LAB_23e7500ba;
                              goto LAB_23e75015d;
                            }
                            if (DAT_23ed6a4c0 == (longlong *)0x0) {
                              in_R10 = plVar16;
                              plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                              iVar5 = (int)puVar23;
                              plStack_b0 = plVar8;
                              plStack_e0 = plVar7;
                              plVar10 = plVar9;
                              plStack_c0 = plVar11;
                              plStack_b8 = plVar25;
                              if (plVar19 == (longlong *)0x0) goto LAB_23e74f0f6;
                              *plVar19 = *plVar19 + 1;
                              DAT_23ed6a4c0 = plVar19;
                            }
                            pcStack_a8 = pcStack_170;
                            uStack_a0 = uVar3;
                            lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_a8);
                            if (lVar12 == 0) {
                              apcStack_88[0] = *(code **)(param_1 + 0x70);
                              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_90 = *(code **)(param_1 + 0x68);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23e75011c;
                            }
                            plVar16[4] = lVar12;
                            plVar10 = DAT_23eed9128;
                            *DAT_23eed9128 = *DAT_23eed9128 + 1;
                            plVar16[5] = (longlong)plVar10;
                            plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                            *plVar16 = *plVar16 + -1;
                            if (*plVar16 == 0) {
                              (**(code **)(plVar16[1] + 0x30))();
                            }
                            if (plVar10 != (longlong *)0x0) {
                              *(undefined4 *)(plVar1 + 5) = 0x310;
                              plVar16 = (longlong *)FUN_23e914090(param_1,plVar13);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                (**(code **)(plVar13[1] + 0x30))();
                              }
                              *plVar10 = *plVar10 + -1;
                              if (*plVar10 == 0) {
                                (**(code **)(plVar10[1] + 0x30))();
                              }
                              if (plVar16 != (longlong *)0x0) {
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                                }
                                lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                plVar1 = *(longlong **)(lVar12 + 0x28);
                                plVar10 = (longlong *)plVar1[2];
                                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                     *(undefined8 *)(lVar12 + 0x30);
                                *(undefined4 *)(plVar1 + 8) = 0xffffffff;
                                if (plVar10 != (longlong *)0x0) {
                                  plVar1[2] = 0;
                                  *plVar10 = *plVar10 + -1;
                                  if (*plVar10 == 0) {
                                    (**(code **)(plVar10[1] + 0x30))();
                                  }
                                }
                                *plVar1 = *plVar1 + -1;
                                if (*plVar1 == 0) {
                                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                                }
                                pcVar14 = _Py_NoneStruct_exref;
                                plVar1[0xf] = 0;
                                *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                *plVar8 = *plVar8 + -1;
                                if (*plVar8 == 0) {
                                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                                }
                                *plVar11 = *plVar11 + -1;
                                if (*plVar11 == 0) {
                                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                                }
                                lVar12 = *plStack_188;
                                *plStack_188 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  (**(code **)(plStack_188[1] + 0x30))(plStack_188);
                                }
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                }
                                lVar12 = *(longlong *)pcStack_190;
                                *(longlong *)pcStack_190 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  (**(code **)(*(longlong *)(pcStack_190 + 8) + 0x30))(pcStack_190);
                                }
                                lVar12 = *plStack_178;
                                *plStack_178 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  (**(code **)(plStack_178[1] + 0x30))(plStack_178);
                                }
                                lVar12 = *(longlong *)pcStack_170;
                                *(longlong *)pcStack_170 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  (**(code **)(*(longlong *)(pcStack_170 + 8) + 0x30))(pcStack_170);
                                }
                                if ((pcStack_180 != (code *)0x0) &&
                                   (lVar12 = *(longlong *)pcStack_180,
                                   *(longlong *)pcStack_180 = lVar12 + -1, lVar12 + -1 == 0)) {
                                  (**(code **)(*(longlong *)(pcStack_180 + 8) + 0x30))(pcStack_180);
                                }
                                if ((pcVar17 != (code *)0x0) &&
                                   (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1,
                                   *(longlong *)pcVar17 == 0)) {
                                  (**(code **)(*(longlong *)((longlong)pcVar17 + 8) + 0x30))
                                            (pcVar17);
                                }
                                if ((plStack_168 != (longlong *)0x0) &&
                                   (lVar12 = *plStack_168, *plStack_168 = lVar12 + -1,
                                   lVar12 + -1 == 0)) {
                                  (**(code **)(plStack_168[1] + 0x30))(plStack_168);
                                }
                                if ((plStack_160 != (longlong *)0x0) &&
                                   (lVar12 = *plStack_160, *plStack_160 = lVar12 + -1,
                                   lVar12 + -1 == 0)) {
                                  (**(code **)(plStack_160[1] + 0x30))(plStack_160);
                                }
                                if ((plStack_158 != (longlong *)0x0) &&
                                   (lVar12 = *plStack_158, *plStack_158 = lVar12 + -1,
                                   lVar12 + -1 == 0)) {
                                  (**(code **)(plStack_158[1] + 0x30))(plStack_158);
                                }
                                if ((plStack_150 != (longlong *)0x0) &&
                                   (lVar12 = *plStack_150, *plStack_150 = lVar12 + -1,
                                   lVar12 + -1 == 0)) {
                                  (**(code **)(plStack_150[1] + 0x30))(plStack_150);
                                }
                                if ((plStack_148 != (longlong *)0x0) &&
                                   (lVar12 = *plStack_148, *plStack_148 = lVar12 + -1,
                                   lVar12 + -1 == 0)) {
                                  (**(code **)(plStack_148[1] + 0x30))(plStack_148);
                                }
                                if ((plStack_140 != (longlong *)0x0) &&
                                   (lVar12 = *plStack_140, *plStack_140 = lVar12 + -1,
                                   lVar12 + -1 == 0)) {
                                  (**(code **)(plStack_140[1] + 0x30))(plStack_140);
                                }
                                if ((plStack_138 != (longlong *)0x0) &&
                                   (lVar12 = *plStack_138, *plStack_138 = lVar12 + -1,
                                   lVar12 + -1 == 0)) {
                                  (**(code **)(plStack_138[1] + 0x30))(plStack_138);
                                }
                                *plVar25 = *plVar25 + -1;
                                if (*plVar25 != 0) {
                                  return pcVar14;
                                }
                                (**(code **)(plVar25[1] + 0x30))(plVar25);
                                return pcVar14;
                              }
                              goto LAB_23e750088;
                            }
                            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pcStack_90 = *(code **)(param_1 + 0x68);
                            apcStack_88[0] = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              FUN_23a334bc0();
                              goto joined_r0x00023e750157;
                            }
                            if (apcStack_88[0] == (code *)0x0) goto LAB_23e75015d;
                            plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
                          }
                          pcVar14 = apcStack_88[0];
                          if (plVar1 == plVar10) goto LAB_23e74cdb2;
                          in_R10 = (longlong *)&DAT_23ed6a4f8;
                          iVar5 = 0x310;
                          goto LAB_23e74cd15;
                        }
                        auVar24 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcVar14 = *(code **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        pcVar20 = *(code **)(param_1 + 0x68);
                      }
                    }
                  }
                }
                in_R10 = (longlong *)&DAT_23ed6a4f8;
                apcStack_88[0] = (code *)0x0;
                _auStack_98 = (undefined1  [16])0x0;
                lVar12 = *(longlong *)pcVar18;
                *(longlong *)pcVar18 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
                }
                pcVar18 = *(code **)(param_1 + 0x138);
                iVar5 = 0x30e;
                goto LAB_23e74f35d;
              }
              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_90 = *(code **)(param_1 + 0x68);
              apcStack_88[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (apcStack_88[0] == (code *)0x0) goto LAB_23e74ee79;
              if (plVar1 == *(longlong **)(apcStack_88[0] + 0x18)) goto LAB_23e74de3b;
              in_R10 = (longlong *)&DAT_23ed6a4f8;
              pcVar17 = (code *)0x0;
              plStack_138 = (longlong *)0x0;
              iVar5 = 0x2f3;
              plStack_140 = (longlong *)0x0;
              plStack_148 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_168 = (longlong *)0x0;
              pcStack_170 = (code *)0x0;
              plStack_178 = (longlong *)0x0;
              pcStack_180 = (code *)0x0;
              goto LAB_23e74cd15;
            }
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            lVar12 = *plStack_178;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plStack_178 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(plStack_178[1] + 0x30))();
            }
            if (apcStack_88[0] == (code *)0x0) goto LAB_23e74ee79;
            if (plVar1 != *(longlong **)(apcStack_88[0] + 0x18)) {
              plStack_138 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              in_R10 = (longlong *)&DAT_23ed6a4f8;
              iVar5 = 0x2f3;
              plStack_140 = (longlong *)0x0;
              plStack_148 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_168 = (longlong *)0x0;
              pcStack_180 = (code *)0x0;
              plStack_178 = (longlong *)0x0;
              pcStack_170 = (code *)0x0;
              goto LAB_23e74cd15;
            }
          }
LAB_23e74de3b:
          plStack_138 = (longlong *)0x0;
          pcVar17 = (code *)0x0;
          plStack_140 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_158 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_168 = (longlong *)0x0;
          pcStack_180 = (code *)0x0;
          pcStack_170 = (code *)0x0;
          plStack_178 = (longlong *)0x0;
          pcVar14 = apcStack_88[0];
          goto LAB_23e74cdb2;
        }
        plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        iVar5 = (int)pcVar14;
        if (plVar13 != (longlong *)0x0) {
          *plVar13 = *plVar13 + 1;
          DAT_23ed6a4c0 = plVar13;
          goto LAB_23e74c239;
        }
LAB_23e74f0f6:
        PyErr_PrintEx(0);
        pcVar18 = (code *)Py_Exit(1);
LAB_23e74f109:
        pcStack_90 = pcVar18;
        plVar8 = plStack_b0;
        plVar7 = plStack_e0;
        plVar9 = plVar10;
        plVar11 = plStack_c0;
        plVar25 = plStack_b8;
        if ((pcVar18 == pcStack_f8) || (pcVar18 == (code *)0x0)) {
          auVar24 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
          pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
          iVar5 = 0x2fb;
          *(longlong *)auVar24 = *(longlong *)auVar24 + 1;
LAB_23e7505dc:
          pcVar18 = *(code **)(param_1 + 0x138);
          pcVar14 = (code *)0x0;
LAB_23e74f35d:
          *(longlong **)(param_1 + 0x138) = plStack_118;
          if (pcVar18 != (code *)0x0) goto LAB_23e74f18b;
        }
        else {
          auVar24 = *(undefined1 (*) [8])(pcVar18 + 8);
          pcVar14 = *(code **)(pcVar18 + 0x28);
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
          *(longlong *)auVar24 = *(longlong *)auVar24 + 1;
          pcVar20 = pcVar18;
          if (pcVar14 == (code *)0x0) goto LAB_23e7505dc;
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
          if (*(longlong **)(pcVar14 + 0x18) == plVar1) {
            *(undefined4 *)(plVar1 + 5) = *(undefined4 *)(pcVar14 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = plStack_118;
LAB_23e74f18b:
          apcStack_88[0] = (code *)0x0;
          _auStack_98 = (undefined1  [16])0x0;
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
          if (*(longlong *)pcVar18 == 0) {
            (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
          }
        }
        auStack_98 = auVar24;
        pcStack_90 = pcVar20;
        if (pcVar14 == (code *)0x0) {
          apcStack_88[0] = (code *)0x0;
          if (iVar5 == 0) {
            iVar5 = (int)plVar1[5];
          }
          goto LAB_23e74d80f;
        }
        if (*(longlong **)(pcVar14 + 0x18) == plVar1) goto LAB_23e74cdb2;
        apcStack_88[0] = pcVar14;
        if (iVar5 == 0) {
          iVar5 = (int)plVar1[5];
        }
      }
      else {
        iVar5 = *(int *)(lVar12 + 0xc);
        if (*(int *)(lVar12 + 0xc) == 0) {
          *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
          iVar5 = DAT_23ec1545c;
          DAT_23ec1545c = DAT_23ec1545c + 1;
        }
        if (_DAT_23ec15444 != iVar5) {
          _DAT_23ec15444 = iVar5;
          _DAT_23eedae30 =
               FUN_23e8cbd60(lVar12,_DAT_23eed9140,*(undefined8 *)(_DAT_23eed9140 + 0x18));
        }
        if (-1 < _DAT_23eedae30) {
          lVar15 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
          lVar22 = *(longlong *)(lVar15 + 8 + _DAT_23eedae30 * 0x10);
          if (lVar22 != 0) goto LAB_23e74bffa;
          _DAT_23eedae30 =
               FUN_23e8cbd60(lVar12,_DAT_23eed9140,*(undefined8 *)(_DAT_23eed9140 + 0x18));
          if (-1 < _DAT_23eedae30) {
            lVar22 = *(longlong *)(lVar15 + 8 + _DAT_23eedae30 * 0x10);
            goto LAB_23e74db78;
          }
        }
LAB_23e74d4a9:
        plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9140);
        if ((plVar9 != (longlong *)0x0) && (lVar22 = *plVar9, lVar22 != 0)) goto LAB_23e74bffa;
        FUN_23e915740(param_1,auStack_98,_DAT_23eed9140);
        pcVar14 = apcStack_88[0];
        auVar24 = auStack_98;
        pcVar17 = pcStack_90;
LAB_23e74d64b:
        auStack_98 = auVar24;
        pcStack_90 = pcVar17;
        if (pcVar14 == (code *)0x0) {
          pcStack_130 = _PyRuntime_exref;
          pcVar17 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          in_R10 = (longlong *)&DAT_23ed6a4f8;
          iVar5 = 0x2f1;
          plStack_140 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_158 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_168 = (longlong *)0x0;
          pcStack_180 = (code *)0x0;
          pcStack_170 = (code *)0x0;
          plStack_178 = (longlong *)0x0;
          pcStack_190 = (code *)0x0;
          plStack_188 = (longlong *)0x0;
          apcStack_88[0] = (code *)0x0;
          goto LAB_23e74d80f;
        }
        plStack_138 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_158 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        pcStack_180 = (code *)0x0;
        pcStack_170 = (code *)0x0;
        plStack_178 = (longlong *)0x0;
        pcStack_190 = (code *)0x0;
        plStack_188 = (longlong *)0x0;
        if (plVar1 == *(longlong **)(pcVar14 + 0x18)) goto LAB_23e74cdb2;
        in_R10 = (longlong *)&DAT_23ed6a4f8;
        iVar5 = 0x2f1;
        pcStack_130 = _PyRuntime_exref;
        apcStack_88[0] = pcVar14;
      }
    }
LAB_23e74cd15:
    pcVar18 = apcStack_88[0];
    pcVar14 = (code *)*in_R10;
    if (pcVar14 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      *in_R10 = *(longlong *)pcVar14;
      *(longlong *)pcVar14 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar14 + 0x18) = plVar1;
    *plVar1 = *plVar1 + 1;
    lVar12 = *(longlong *)(pcStack_130 + 0x1f8);
    *(int *)(pcVar14 + 0x24) = iVar5;
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar15 = *(longlong *)(pcVar14 + -8);
    puVar23 = *(undefined8 **)(lVar12 + 8);
    *puVar23 = pcVar14 + -0x10;
    *(longlong *)(pcVar14 + -0x10) = lVar12;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar23;
    *(code **)(lVar12 + 8) = pcVar14 + -0x10;
    *(code **)(pcVar14 + 0x10) = pcVar18;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
    }
  }
LAB_23e74cdb2:
  apcStack_88[0] = pcVar14;
  FUN_23e8bba40(plVar1,"ooooooooooooooooooo",plVar25,plVar7,plVar8,plVar11,plStack_188,plVar9,
                pcStack_190,plStack_178,pcStack_170,pcStack_180,pcVar17,plStack_168,plStack_160,
                plStack_158,plStack_150,plStack_148,plStack_140,plStack_138,0);
  if (_DAT_23eedae38 == plVar1) {
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    _DAT_23eedae38 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar1 = *(longlong **)(lVar12 + 0x28);
  plVar10 = (longlong *)plVar1[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar1 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar1[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  pcVar18 = apcStack_88[0];
  pcVar14 = pcStack_90;
  auVar24 = auStack_98;
  plVar1[0xf] = 0;
  _auStack_98 = (undefined1  [16])0x0;
  apcStack_88[0] = (code *)0x0;
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plStack_188 != (longlong *)0x0) &&
     (lVar12 = *plStack_188, *plStack_188 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_188[1] + 0x30))(plStack_188);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((pcStack_190 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_190, *(longlong *)pcStack_190 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_190 + 8) + 0x30))(pcStack_190);
  }
  if ((plStack_178 != (longlong *)0x0) &&
     (lVar12 = *plStack_178, *plStack_178 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_178[1] + 0x30))(plStack_178);
  }
  if ((pcStack_170 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_170, *(longlong *)pcStack_170 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_170 + 8) + 0x30))(pcStack_170);
  }
  if ((pcStack_180 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_180, *(longlong *)pcStack_180 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_180 + 8) + 0x30))(pcStack_180);
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)((longlong)pcVar17 + 8) + 0x30))(pcVar17);
  }
  if ((plStack_168 != (longlong *)0x0) &&
     (lVar12 = *plStack_168, *plStack_168 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_168[1] + 0x30))(plStack_168);
  }
  if ((plStack_160 != (longlong *)0x0) &&
     (lVar12 = *plStack_160, *plStack_160 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_160[1] + 0x30))(plStack_160);
  }
  if ((plStack_158 != (longlong *)0x0) &&
     (lVar12 = *plStack_158, *plStack_158 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_158[1] + 0x30))(plStack_158);
  }
  if ((plStack_150 != (longlong *)0x0) &&
     (lVar12 = *plStack_150, *plStack_150 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_150[1] + 0x30))(plStack_150);
  }
  if ((plStack_148 != (longlong *)0x0) &&
     (lVar12 = *plStack_148, *plStack_148 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_148[1] + 0x30))(plStack_148);
  }
  if ((plStack_140 != (longlong *)0x0) &&
     (lVar12 = *plStack_140, *plStack_140 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_140[1] + 0x30))(plStack_140);
  }
  if ((plStack_138 != (longlong *)0x0) &&
     (lVar12 = *plStack_138, *plStack_138 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_138[1] + 0x30))(plStack_138);
  }
  *plVar25 = *plVar25 + -1;
  apcStack_88[0] = pcVar18;
  auStack_98 = auVar24;
  pcStack_90 = pcVar14;
  if (*plVar25 == 0) {
    (**(code **)(plVar25[1] + 0x30))(plVar25);
  }
  FUN_23a33aa70(param_1,auStack_98,pcStack_90,apcStack_88[0]);
  return (code *)0x0;
}
